#include<bits/stdc++.h>
using namespace std;
typedef long long lld;
lld n,k,sp1,sp2,sp3,ans;int a[500010],dp[500010],jp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){sp1++,sp2++,sp3++;}
		else if(a[i]<=1){sp2++,sp3++;}
		else if(a[i]<=255)sp3++;
	}
	if(sp1==n){
		if(k==1){cout<<n;return 0;}
		if(k==0){cout<<n/2;return 0;}
		cout<<0;return 0;
	}
	if(sp2==n){
		if(k==0){
			int f=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++,f=0;
				if(a[i]==1){
					if(f==0)f=1;
					else{
						ans++,f=0;
					}
				}
			}
			cout<<ans;return 0;
		}else if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;return 0;
		}else{
			cout<<0;return 0;
		}
	}
	
	
	for(int i=1;i<=n;i++){
		int x;
		if(a[i]==k){
			//cout<<i<<'\n';
			jp[i]=i;
			for(int w=i;w<=n;w++)dp[w]++;
			for(int w=i+1;w<=n+1;w++)dp[w]=dp[i]+1;
			//for(int w=1;w<=n;w++)cout<<dp[w]<<' ';cout<<'\n';
			continue;
		}
		for(int j=i+1;j<=n;j++){
			x=a[i];x^=a[j];
			if(x==k){
				//cout<<i<<' '<<j<<'\n';
				jp[i]=j;
				if(dp[j]<dp[i]+1){
					for(int w=j+1;w<=n+1;w++)dp[w]=dp[i]+1;
				}
				//for(int w=1;w<=n;w++)cout<<dp[w]<<' ';cout<<'\n';
				break;
			}
		}
	}
	ans=0;
	for(int i=1;i<=n+1;i++)ans=max(1ll*dp[i],ans);
	cout<<ans;
	return 0;
}