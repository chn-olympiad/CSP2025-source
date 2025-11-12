#include<bits/stdc++.h>
using namespace std;
int n,m,s1[50006],ans=0,s2[50006];
bool book[50006];
void dfs(int x,int y,int z){
	if(x>n){
		ans+=max(y,m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(book[i]){
			continue;
		}
		book[i]=1;
		if(z>=s2[i]){
			dfs(x+1,y,z+1);
		}
		else{
			dfs(x+1,y+s1[x],z+s1[x]);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s1[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>s2[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

