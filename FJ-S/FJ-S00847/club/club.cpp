#include<bits/stdc++.h>
#define reg register
using namespace std;
int t;
const int N=1e5+5;
struct node{
	int a,b,c;
}stu[N];
void bfs(int now,int n1,int n2,int n3,long long as);
long long ans[1000005];int n,cnt;
bool cmp(node a,node b){
	return a.a>b.a;
}
void solved1(){
	int n;
	scanf("%d",&n);
	for(reg int i=1;i<=n;i++)
		scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);	
	sort(stu+1,stu+n+1,cmp);
	long long ans=0;
	for(reg int i=1;i<=n/2;i++){
		ans+=stu[i].a;
	}
	printf("%lld\n",ans);
}
void solved(){
	scanf("%d",&n);
	bool pd=0;
	for(reg int i=1;i<=n;i++){
		scanf("%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c);
		if(stu[i].b!=0||stu[i].c!=0)pd=1;
	}
	if(!pd)solved1();
	cnt=0;
	long long maxx=-1;
	if(pd&&n<=14){
		bfs(1,0,0,0,0);
		for(reg int i=1;i<=cnt;i++){
			maxx=max(ans[i],maxx);
		}
		printf("%lld\n",maxx);
	}
}
void bfs(int now,int n1,int n2,int n3,long long as){
	if(now>n){
		ans[++cnt]=as; 
		return;
	}
	if(n1<n/2){
		bfs(now+1,n1+1,n2,n3,as+stu[now].a);
	}
	if(n2<n/2){
		bfs(now+1,n1,n2+1,n3,as+stu[now].b);
	}
	if(n3<n/2){
		bfs(now+1,n1,n2,n3+1,as+stu[now].c);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)solved();
	return 0;
}
