//employ
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=998244353;
int n,m,cnt;
string s;
int c[510];
ll dp[262144][19],ans;
void slva(){
	dp[0][0]=1;
	for(int i=1;i<1<<n;i++){
		cnt=0;
		for(int j=0;j<n;j++){
			if(i>>j&1) cnt++;
		}
		for(int j=0;j<n;j++){
			if(!(i>>j&1)) continue;
			for(int k=0;k<cnt;k++){
				if(cnt-k-1>=c[j]||s[cnt-1]=='0') dp[i][k]=(dp[i][k]+dp[i-(1<<j)][k])%M;
				else dp[i][k+1]=(dp[i][k+1]+dp[i-(1<<j)][k])%M;
			}
		}
	}
	for(int i=m;i<=n;i++) ans=(ans+dp[(1<<n)-1][i])%M;
	printf("%lld",ans);
}
void slvb(){
	for(int i=0;i<n;i++){
		if(c[i]==0) cnt++;
	}
	n-=cnt;
	if(n>=m){
		ans=1;
		for(int i=1;i<=n;i++) ans=ans*i%M;
	}else ans=0;
	printf("%lld",ans);
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=0;i<n;i++) scanf("%d",c+i);
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			slva();
			return 0;
		}
	}
	slvb();
	return 0;
}
