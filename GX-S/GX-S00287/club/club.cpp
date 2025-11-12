#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct student{
	int a,b,c;
}stu[MAXN];
int n,vis[MAXN]={},ans=0;
void dfs(int an,int bn,int cn,int vn){
	if(an+bn+cn==n){
		ans=max(ans,vn);
		return;
	};
	for(int i=0;i<n;i++){
		if(!vis[i]){
			if(an<n/2){
				vis[i]=true;
				dfs(an+1,bn,cn,vn+stu[i].a);
				vis[i]=false;
			}
			if(bn<n/2){
				vis[i]=true;
				dfs(an,bn+1,cn,vn+stu[i].b);
				vis[i]=false;
			}
			if(cn<n/2){
				vis[i]=true;
				dfs(an,bn,cn+1,vn+stu[i].c);
				vis[i]=false;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin >>T;
	while(T--){
		ans=0;
		cin >>n;
		for(int i=0;i<n;i++){
			cin >>stu[i].a >>stu[i].b >>stu[i].c;
		}
		memset(vis,0,sizeof(vis));
		dfs(0,0,0,0);
		cout <<ans <<endl;
	}
	return 0;
}
