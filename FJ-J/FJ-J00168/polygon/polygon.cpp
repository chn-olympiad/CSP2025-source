#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5050],tot,tt=3;
vector<int> u[10050];
bool vis[5050][5050];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void dfs(int num,int t,int sum,int maxx,vector<int> g){
	if(t==0){
		if(sum>(maxx*2)){
			if(tt!=g.size()){
				tt=g.size();
				tot=0;
			}
			for(int i=1;i<=tot;i++) if(u[i]==g) return;
			u[++tot]=g;
			ans++;
			ans%=998244353;
		}
		return;
	}
	g.push_back(num);
	for(int i=num+1;i<=(n-t+2);i++){
		dfs(i,t-1,sum+a[num],a[num],g);
		continue;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=(n-i+2);j++){
			dfs(j,i,0,0,{});
		}
	}
	cout<<ans;
	return 0;
}
