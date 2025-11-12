#include<bits/stdc++.h>
using namespace std;
long long Num[300001][18];
long long ans,mod=998244353;
int nx[18];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Num[0][0]=1;
	int n,m;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>nx[i];
	if(n==m){
		for(int i=0;i<n;i++)if(s[i]=='0'){
			cout<<0;
			return 0;
		}
		for(int i=0;i<n;i++)if(nx[i]==0){
			cout<<0;
			return 0;
		}
		long long A=1;
		for(long long i=1;i<=n;i++)(A*=i)%=mod;
		cout<<A;
		return 0;
	}
	for(int i=0;i<(1<<n);i++){
		int popc=__builtin_popcount(i)+1;
		for(int j=0;j<n;j++){
			if(i&(1<<j))continue;
			int to=i|(1<<j);
			for(int k=0;k<popc;k++){
				//现在在第popc天，从状态i到状态to，第j个人正在进行面试，前面k个人已经放弃，popc-1-k个人过关
				//如果第popc天，s[popc]==0或者k>=nx[j]则Num[i][k]转移到Num[to][k+1]
				//否则Num[i][k]转移到Num[to][k]
				if(s[popc-1]=='0'||k>=nx[j])(Num[to][k+1]+=Num[i][k])%=mod;
				else (Num[to][k]+=Num[i][k])%=mod;
			}
		}
	}
	//for(int i=0;i<(1<<n);i++)for(int j=0;j<=n;j++)cerr<<Num[i][j]<<" ";
	for(int j=n-m;j>=0;j--)(ans+=Num[(1<<n)-1][j])%=mod;
	cout<<ans;
	return 0;
}
