#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m;
int s[N];
int c[N];
int ans;
int vis[N];
void dfs(int mem,int day){
	if(mem>=m){
		ans++;
		return;
	}
	if(!s[day]){
		for(int i=day;i<=n;i++){
			c[i]--;
		}
	}
	for(int i=day;i<=n;i++){
		if(!vis[i]){
			if(c[i]>0){
				vis[i]=1;
				dfs(mem+1,i);
			}else{
				vis[i]=1;
				dfs(mem,i);
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		dfs(1,i);
	}
	cout<<ans;
	
	
	return 0;
}
