#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const long long N=510,MOD=998244353;
typedef long long ll;
int n,m,c[N],alls;
bool s[N],specA=1,specB=1,vis[N];
char f[N];
ll dfs(int orz,int ac,int gu){
	if(orz==n&&ac>=m){
		return 1;
	}
	if(n-orz<m-ac)return 0;
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[i]&&c[i]>gu){
				sum+=dfs(orz+1,ac+1,0);
			}else{
				sum+=dfs(orz+1,ac,gu+1);
			}
			vis[i]=0; 
		}
		sum%=MOD;
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>f;
	for(int i=1;i<=n;i++){
		s[i]=f[i]-'0';
		if(!s[i])specA=0;
		if(s[i])alls++;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(c[i]!=0){
			vis[i]=1;
			if(s[i])sum=sum+dfs(1,1,0);
			else sum=sum+dfs(1,0,1);
			sum%=MOD;
			vis[i]=0;
		}
	}
	cout<<sum;
	return 0;
}
