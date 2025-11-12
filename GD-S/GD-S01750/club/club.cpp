#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=200001;
struct node{
	int a,b,c;
};
node stu[N];
int vis[N];
int t;
int ans;int n;
void dfs(int id,int an,int bn,int cn,int total){
//	cout<<"ID:"<<id<<endl;
//	cout<<"total:"<<total<<endl;
	if (an>n/2)return;
	if (bn>n/2)return;
	if (cn>n/2)return;
	if (an+bn+cn==n||id==4){
		ans=max(ans,total); 
		return;
	}
	if (an<n/2)dfs(id+1,an+1,bn,cn,total+stu[id+1].a);
	if (bn<n/2)dfs(id+1,an,bn+1,cn,total+stu[id+1].b);
	if (cn<n/2)dfs(id+1,an,bn,cn+1,total+stu[id+1].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t){
		memset(vis,0,sizeof(vis));
		ans=0;
		t--;
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);
		}
		
		dfs(1,1,0,0,stu[1].a);
		dfs(1,0,1,0,stu[1].b);
		dfs(1,0,0,1,stu[1].c);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
