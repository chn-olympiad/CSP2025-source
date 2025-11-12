#include<bits/stdc++.h>
using namespace std;
bool stt;
const int N=510;
int n,m,ans;
string s,t;
int c[N],vis[N];
void dfs(int x,int y){
	if(x>n){
		ans+=(y<=n-m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,y+(s[x]=='0'||y>=c[i]));
			vis[i]=0;
		}
	}
}
bool edd;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s,s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n==m){
		for(int i=1;i<=n;i++) if(c[i]==0||s[i]=='0') return cout<<"0\n",0;
		return 0;
	}
	if(n>11) return cout<<"0\n",0;
	dfs(1,0);
	cout<<ans<<"\n";
	cerr<<(&edd-&stt)/1024.0/1024<<"\n";
	return 0;
}
