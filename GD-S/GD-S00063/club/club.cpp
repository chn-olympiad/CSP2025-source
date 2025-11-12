#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,ans;
int d[4],p[100005][4];
struct node{
	int id,x;
}a[4];
struct pp{
	int id[4],x[4];
}maxn[100005];
bool cmp1(node a,node b){
	return a.x>b.x;
}
bool cmp2(pp a,pp b){
	if(a.x[1]!=b.x[1])return a.x[1]>b.x[1];
	if(a.x[2]!=b.x[2])return a.x[2]>b.x[2];
	return a.x[3]>b.x[3];
}
void work(int num,int s1,int s2,int s3,int s){
	if(num==n){
		ans=max(ans,s);
		return;
	}
	if(s1<n/2)work(num+1,s1+1,s2,s3,s+p[num+1][1]);
	if(s2<n/2)work(num+1,s1,s2+1,s3,s+p[num+1][2]);
	if(s3<n/2)work(num+1,s1,s2,s3+1,s+p[num+1][3]);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		if(n<=15){
			for(i=1;i<=n;i++){
				for(j=1;j<=3;j++)scanf("%d",&p[i][j]);
			}
			ans=0;
			work(0,0,0,0,0);
			printf("%d\n",ans);
			continue;
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=3;j++){
				scanf("%d",&a[j].x);
				a[j].id=j;
			}
			sort(a+1,a+4,cmp1);
			for(j=1;j<=3;j++){
				maxn[i].x[j]=a[j].x;
				maxn[i].id[j]=a[j].id;
			}
		}
		sort(maxn+1,maxn+n+1,cmp2);
		for(i=1;i<=3;i++)d[i]=n/2;
		ans=0;
		for(i=1;i<=n;i++){
			if(d[maxn[i].id[1]]){
				d[maxn[i].id[1]]--;
				ans+=maxn[i].x[1];
				continue;
			}
			if(d[maxn[i].id[2]]){
				d[maxn[i].id[2]]--;
				ans+=maxn[i].x[2];
				continue;
			}
			if(d[maxn[i].id[3]]){
				d[maxn[i].id[3]]--;
				ans+=maxn[i].x[3];
			}
		}
		printf("%d\n",ans);
	}
}
