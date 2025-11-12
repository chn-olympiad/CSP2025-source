#include<bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,m,dp[1<<18][19],c[505],d[505],ans,tot,k;
int C[505][505];
string s;
void Sub1(){
	dp[0][0]=1;
	for(int i=1;i<(1<<n);i++){
		int siz=__builtin_popcount(i);
		for(int j=0;j<n;j++)
			if(i&(1<<j))
				for(k=0;k<=siz;k++){
					if(s[siz-1]=='0'){
						dp[i][k]=(dp[i][k]+dp[i^(1<<j)][k])%md;
					}
					else{
						if(k!=0)if(c[j+1]>siz-1-(k-1))dp[i][k]=(dp[i][k]+dp[i^(1<<j)][k-1])%md;
						if(c[j+1]<=siz-1-k&&s[siz-1]=='1')dp[i][k]=(dp[i][k]+dp[i^(1<<j)][k])%md;
					}
				}
	}
	for(int i=m;i<=n;i++)ans=(ans+dp[(1<<n)-1][i])%md;
	cout<<ans;
}
void Sub2(){
	
}
void Sub3(){
	tot=1;
	for(int i=1;i<=n;i++)tot=tot*1ll*i%md;
	ans=1;
	for(int i=1;i<=n;i++)
		if(s[i-1]=='1'){
			k++;
			d[i]=1;
			while(d[i]<=n&&c[d[i]]<=i-1)d[i]++;
			d[i]--;
			if(d[i]<=i-1){
				ans=0;
				break;
			}
			ans=ans*1ll*(d[i]-k+1)%md;
		}
	for(int i=1;i<=n-k;i++)ans=1ll*ans*i%md;
	cout<<(tot-ans+md)%md;
}
void Sub4(){
	for(int i=1;i<=n;i++)
		if(c[i]==0){
			cout<<"0";
			return;
		}
	ans=1;
	for(int i=1;i<=n;i++)ans=ans*1ll*i%md;
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	C[0][0]=1;
	for(int i=1;i<=n;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%md;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+n+1);
	if(n<=18)Sub1();
	else{
		if(m==1)Sub3();
		else if(m==n)Sub4();
		else{
			bool f=1;
			for(int i=0;i<n;i++)
				if(s[i]=='0')f=0;
			if(f)Sub2();
		}
	}
	return 0;
}
//32pts
