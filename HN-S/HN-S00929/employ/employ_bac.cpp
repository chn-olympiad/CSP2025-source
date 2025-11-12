//16 39 2/2 8pts
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=500+5,mod=998244353;
int n,m,s[N],c[N],t[N];
bool a[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool f=true;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=c=='1';
		if(!a[i]){
			f=false;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		t[i]=i;
	}
	int ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[t[i]]||!a[i]){
				cnt++;
			}
		}
		if(n-cnt>=m){
			ans++;
			ans%=mod;
		}
	}while(next_permutation(t+1,t+1+n));
	cout<<ans;
	return 0;
}

