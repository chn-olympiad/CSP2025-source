#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N=502,MOD=998244353;
int n,m,cnt;
char ch;
string s;
int c[N];
int a[N];
bool vis[N];
void dfs(int dep){
	if(dep>n){
		int tmp=0,h=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='1'&&a[i]>=tmp)h++,tmp++;
			if(s[i-1]=='0')tmp++;
		}
		if(h>=m)cnt++;
		cnt%=MOD;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		a[dep]=c[i];
		dfs(dep+1);
		vis[i]=0;
	}
}
bool flag=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ch;
		s+=ch;
		if(ch!='1')flag=0;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(flag){
		for(int i=m;i<=n;i++){
		int ans=1;
		for(int j=1;j<=i;j++){
			ans*=j;
			ans%=MOD;
		}
		cnt+=ans;
		cnt%=MOD;
	}
		cout<<cnt;
		return 0;
	}
	dfs(1);
	cout<<cnt;
}
