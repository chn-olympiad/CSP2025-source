#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n[5005],sum=0,ans=0,m,s=0;
void dfs(int k,int ma){
	if(ma*2<sum&&s>=3){
		ans++;
	}
	for(int i=k+1;i<=m;i++){
		sum+=n[i];s++;
		dfs(i,max(ma,n[i]));
		sum-=n[i];s--;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>m;
	bool flag=1;
	for(int i=1;i<=m;i++){
		cin>>n[i];
		if(n[i]!=1) flag=0;
	}
	if(flag){
		for(int i=3;i<m;i++){
			for(int j=i+1,k=m-i;j<=i;j++){
				if(k!=1){
					if(j%k==0){
						ans*=(j/k);
						ans%=mod;
						k--;
					}else{
						ans*=j;
						ans%=mod;
					}
				}else{
					ans*=j;
					ans%=mod;
				}
			}
		}
		ans++;
		cout<<ans%mod<<endl;
		return 0;
	}
	dfs(0,0);
	cout<<ans%mod<<endl;
}/*
bu yao kou pi gu
sui ran hen shu fu
shou shang you bing du
hui gan ran pi gu
pi gu ye you du
kou wan shou you du
zai qu chi shi wu
jiu rong yi zhong du
la la la la la la 
bu yao kou pi gu
la la la la la la
bu yao kou pi gu
*/
