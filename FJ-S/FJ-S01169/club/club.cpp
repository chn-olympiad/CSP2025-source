#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
struct node{
	int a,b,c;
};
node stu[100005];
int max(int a,int b){
	return (a>b?a:b);
} 
bool cmp1(node a,node b){
	return a.a>b.a;
}
int ans=0;
void dfs(int k,int s1,int s2,int s3,int sum){
	if(k>n){
		ans=max(ans,sum);
		return ;
	}
	if(s1<n/2)dfs(k+1,s1+1,s2,s3,sum+stu[k].a);
	if(s2<n/2)dfs(k+1,s1,s2+1,s3,sum+stu[k].b);
	if(s3<n/2)dfs(k+1,s1,s2,s3+1,sum+stu[k].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		bool fa=1;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);
			if(stu[i].b!=0||stu[i].c!=0)fa=0;
		}
		if(fa){
			sort(stu+1,stu+n+1,cmp1);
			for(int i=1,j=0;i<=n/2;i++,j++){
				ans+=stu[j].a;
			}
			printf("%d\n",ans);
			continue;
		}
		dfs(0,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
} 

