#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,p[N],s[N],ans;
bool vis[N];
string x;
void dfs(int step,int cnt){
	if(step>n){
		ans+=cnt>m;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(step+1,cnt+(s[step-1]<p[i]));
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]+(x[i-1]=='0');
	s[0]=-1;
	dfs(1,0);
	cout<<ans;
	return 0;
}
