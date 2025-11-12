#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int sum[500005];
map <int,int> m;
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(!k){
        while(n--){
            int x;
            cin>>x;
            ans+=!x;
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        int f=0;
        cin>>a[i];
        if(!a[i]){
            n--,i--;
            continue;
        }
        sum[i]=sum[i-1]^a[i];
        m[sum[i]]|=1;
        if(a[i]==k){
            f=1;
        }
        if(sum[i]==k){
            f=1;
        }
        f|=m[sum[i]^k];
        ans+=f;
        if(f){
			m.clear();
			sum[i]=0;
		}
    }
    cout<<ans;
    return 0;
}
