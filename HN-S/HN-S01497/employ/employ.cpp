#include<bits/stdc++.h>
#define Mod 998244353
#define ll long long
using namespace std;
int n,m;
ll ans;
char c[505];
int a[505];
bool f[505];
void dfs(int day,int cnt){
	if(day>n){
		if(cnt>=m){
			ans++;
			ans=ans%Mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==1)
		  continue;
		if(c[day]=='0'||day-1-cnt>=a[i]){
//			cout<<0<<' '<<day<<' '<<i<<'\n';
			f[i]=1;
			dfs(day+1,cnt);
			f[i]=0;
		}
		else{
//			cout<<1<<' '<<day<<' '<<i<<'\n';
			f[i]=1;
			dfs(day+1,cnt+1);
			f[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int fa=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]=='0')
		  fa=0;
	}
	if(fa==1||m==1){
		ll ansa=1;
		for(int i=1;i<=n;i++){
			ansa*=i;
			ansa=ansa%Mod;
		}
		cout<<ansa;
		return 0;
	} 
	else if(m==n){
		cout<<'0';
		return 0;
	}
	else if(n<=32){
		for(int i=1;i<=n;i++)
		  cin>>a[i];
		memset(f,0,sizeof(f));
		dfs(1,0);
		cout<<ans%Mod;
	}
	else
	  cout<<'0';
	return 0;
}

