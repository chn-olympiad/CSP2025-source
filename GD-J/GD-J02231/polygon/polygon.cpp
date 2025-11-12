#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N],n,ans;
map<long long,bool> m;
map<pair<long long,pair<pair<int,int>,pair<int,int> > >,bool> vis;

void dfs(int i,int sum,int maxx,int ch,long long flag){	
	if(vis[{flag,{{i,ch},{sum,maxx}}}]) return;
	vis[{flag,{{i,ch},{sum,maxx}}}] = 1;
	if(i>n) return ;
	if(sum>maxx*2 && ch>=3 && !m[flag<<n-i]){
		m[flag<<n-i] = 1;
		ans++;
	}
	
	dfs(i+1,sum,maxx,ch,flag<<1);
	for(int j = i+1;j<=n;j++){
		dfs(j,sum+a[j],max(maxx,a[j]),ch+1,(flag<<(j-i))|1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n<3){
		cout<<0;
		return 0;
	}
	
	dfs(1,a[1],a[1],1,1);
	dfs(1,0,0,0,0);
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
