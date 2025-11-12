#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[510],sum[510],id,ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		c[x]++;
	}
	sum[n]=c[n];
	for(int i=n-1;i>=0;i--) sum[i]=sum[i+1]+c[i];
	if(m==1){
		id=n+1;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				id=i;
				break;
			}
		}
		id++;
		for(int i=1;i<=n-1;i++){
			ans=(ans*i)%mod;
		}
		if(!sum[id] || id==n+1) ans=0;
		else ans=(ans*sum[id])%mod;
		printf("%d",ans);
	}else{
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod;
		}
		printf("%d",ans);
	}
	return 0;
}
//32
