#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int i1,i2,i3;
}a[N];
int T,n,ans,cnti1,cnti2,cnti3;
bool TA=true,TB=true;
bool cmpi1(node a,node b){
	return a.i1>b.i1;
}
bool cmpi2(node a,node b){
	return a.i2>b.i2;
}
void dfs(int x,int sum){
	ans=max(ans,sum);
	if(x>n)return;
	if(cnti1+1<=n/2)cnti1++,dfs(x+1,sum+a[x].i1),cnti1--;
	if(cnti2+1<=n/2)cnti2++,dfs(x+1,sum+a[x].i2),cnti2--;
	if(cnti3+1<=n/2)cnti3++,dfs(x+1,sum+a[x].i3),cnti3--;
}
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=cnti1=cnti2=cnti3=0,TA=TB=1;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].i1,&a[i].i2,&a[i].i3);
			TA=TA&&(a[i].i2==0&&a[i].i3==0);
			TB=TB&&(a[i].i3==0);
		}
		if(TA){
			sort(a+1,a+1+n,cmpi1);
			for(int i=1;i<=n/2;i++)ans+=a[i].i1;
			printf("%d\n",ans);
			continue;
		}
		if(TB){
			sort(a+1,a+1+n,cmpi1);
			int t1=0,t2=0,t3=0,t4=0;
			for(int i=1;i<=n/2;i++)t1+=a[i].i1;
			for(int i=n/2+1;i<=n;i++)t3+=a[i].i1;
			sort(a+1,a+1+n,cmpi2);
			for(int i=1;i<=n/2;i++)t2+=a[i].i2;
			for(int i=n/2+1;i<=n;i++)t4+=a[i].i2;
			printf("%d\n",max(t1+t4,t2+t3));
			continue;
		}
		dfs(1,0);
		printf("%d\n",ans);
	}
	return 0;
}

