#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e2+3;
const ll mod=998244353;
int n,m;
int as[N];
ll ans;
bool vis[N];
char c[N];
vector<int> g;
int in(){
	int f=1,ans=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c==45)
			f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		ans=ans*10+c-48;
		c=getchar();
	}
	return f*ans;
}
//inline con(){
//	freopen("con","w",stdout);
//	FILE* t=popen("fc employ.out employ3.ans","r");
//	char c[128];
//	while(fgets(c,sizeof(c),t))
//		printf("%s",c);
//}
bool check(){
	int tot=0,sum=0;
	for(int i=0;i<n;++i){
		if(g[i]<=tot)
			continue;
		if(c[i])
			++sum;
		else
			++tot;
	}
}
void dfs(int x){
	if(x==n){
		if(check())
			++ans;
		return;
	}
	for(int i=0;i<n;++i){
		if(vis[i])
			continue;
		vis[i]=1;
		as[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in(),m=in();
	cin>>c;
	bool fla=1;
	for(int i=0;i<n;++i){
		g.push_back(in());
		if(c[i]=='0')
			fla=0;
	}
	if(fla){
		ans=1;
		for(int i=2;i<=n;++i)
			ans=ans*i%mod;
		printf("%lld\n",ans);
	}
	else{
		dfs(0);
		printf("%lld\n",ans);
	}
//	con();
	return 0;
}
