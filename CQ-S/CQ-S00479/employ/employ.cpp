#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],ans;
string s;
bool vis[505];
void work(){
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(cnt>=a[b[i]])cnt++;
		else{
			if(s[i]=='0')cnt++;
			else sum++;
		}
	}
	if(sum>=m)ans++;
	else return;
//	for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<"\n";
}
void dfs(int step){
	if(step>n){work();return;}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		b[step]=i,vis[i]=1,dfs(step+1),vis[i]=0,b[step]=0;
	}
} 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;s=" "+s;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}


/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
