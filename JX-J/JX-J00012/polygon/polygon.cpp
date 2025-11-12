#include<iostream>
#include<algorithm>

using namespace std;

#define Debug 2
#define steam "polygon"
#define mod 998244353

long long n,a[5010],ans=0,xsum;
bool v[5010];
long long c[5010];

void dfs(int layer=0,int maxi=1) {
    if (layer>=3) {
        if (xsum > 2*a[c[layer]]){
            ans++;
        }

    }
    for(int i=maxi;i<=n;i++) {
        if (!v[i]) {
            xsum+=a[i];
            v[i]=1;
            c[layer+1] = i;
            dfs(layer+1,i+1);
            c[layer+1] = 0;
            v[i]=0;
            xsum-=a[i];
        }
    }
}

int main(){
	if (Debug == 1){
        string c;
        cin>>c;
		freopen((string(steam)+c+".in").c_str(),"r",stdin);
	} else if (Debug == 2) {
		freopen(steam".in","r",stdin);
		freopen(steam".out","w",stdout);
	}
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(0);
    cout<<ans%mod;

	return 0;
}// O(n^n). n<10 cai ke yi guo,
// 24 pts, TLE
