#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=1e5+5,M=1e6+5,hsh=239;
char s[N];
int c[N],st[N],l[N],vs[N]={0},r=0,ans=0,n,m;
void dfs(int now,int tt){
//	cout<<now<<" "<<tt<<'\n';
	if(now==n+1){
		if(tt>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vs[i])continue;
		vs[i]=1;
		dfs(now+1,tt+(s[now]=='1'&&st[now]<c[i]));
		vs[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		st[i]=st[i-1]+(s[i]=='0');
//		cout<<st[i]<<'\n';
		if(s[i]=='1')l[++r]=st[i];
	}for(int i=1;i<=n;i++){
		cin>>c[i];
	}sort(c+1,c+1+m);
	dfs(1,0);cout<<ans;
	return 0;
} 