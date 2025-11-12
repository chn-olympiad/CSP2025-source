#include<bits/stdc++.h>
#define N 25
using namespace std;
const int mod=998244353;
string s;
int n,m,ans,c[N],f[1100000][N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=0;i<n;i++)
		scanf("%d",c+i);
	f[0][0]=1;int mask=(1<<n)-1;
	for(int i=0;i<=mask;i++){
		int cnt=0;
		for(int j=0;j<n;j++)
			if(i&(1<<j)) cnt++;
		for(int j=0;j<n;j++)
			if(!(i&(1<<j)))
				for(int k=0;k<=cnt;k++) 
					if(k<c[j]&&s[cnt]=='1') f[i|(1<<j)][k]=(f[i|(1<<j)][k]+f[i][k])%mod;
					else f[i|(1<<j)][k+1]=(f[i|(1<<j)][k+1]+f[i][k])%mod;
	}
	for(int i=0;n-i>=m;i++)
		ans=(ans+f[mask][i])%mod;
	printf("%d",ans);
	return 0;
}
/*
估分：100+[32,64]+25+20=[177,209]
T2都切不掉，直接去重了。 
*/
