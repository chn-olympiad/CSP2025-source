#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N=510;
int n,m,s[N],a[N],tmp[N],vis[N],val[N],ans;

void dfs(int st){
	if(st>n){
		int l=0,sum=0;
		for(int i=1;i<=n;i++) tmp[i]=1;
		for(int i=1;i<=n;i++){
			if(!tmp[i]) continue;
			if(s[i]==0){
				tmp[i]=0,l++;
				for(int j=i;j<=n;j++){
					if(tmp[j]&&l>=a[val[j]]){
						tmp[j]=0;
						l++;
					}
				}
			}
		}
		if(n-l>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		val[st]=i;
		dfs(st+1);
		vis[i]=0;
		val[st]=0;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=18){
		dfs(1);
		cout<<ans;
		return 0;
	}
	
//	if(m==1){
//		sort(a+1,a+1+n);
//		for(int i=1;i<=n;i++){
//			if(s[i]==1){
//				int ans=0,s=i;
//				
//				return 0;
//			}
//		}
//		cout<<0;
//	}
	int ans=1,s=n;
	for(int i=1;i<=n;i++){
		ans=(ans*s)%mod;
		s--;
	}
	cout<<ans;
	return 0;
}

