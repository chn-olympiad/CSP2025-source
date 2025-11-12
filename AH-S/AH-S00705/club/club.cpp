#include<bits/stdc++.h>
using namespace std;
const int INF=1e5+10;
int t,n,k[INF];
bool flag1[INF],flag2[INF];
struct Node{
	int v1,v2,v3,id;
}a[INF];
int Max1=INT_MIN;
void dfs(int d,int sum,int k1,int k2,int k3){
	if(d==n+1){
		Max1=max(Max1,sum);
		return ;
	}
	if(k1<n/2) dfs(d+1,sum+a[d].v1,k1+1,k2,k3);
	if(k2<n/2) dfs(d+1,sum+a[d].v2,k1,k2+1,k3);
	if(k3<n/2) dfs(d+1,sum+a[d].v3,k1,k2,k3+1);
}
bool cmp1(Node x,Node y){
	return x.v1>y.v1;
}
bool cmp2(Node x,Node y){
	return x.v2>y.v2;
}
bool cmp3(Node x,Node y){
	return x.v3>y.v3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int flag=0,fl=0;
		for(int i=1; i<=n; i++){
			scanf("%d %d %d",&a[i].v1,&a[i].v2,&a[i].v3);
			if(a[i].v2!=0||a[i].v3!=0) flag=-1;
			if(a[i].v3!=0) fl=-1;
			a[i].id=i;
		}
		if(flag==0){
			sort(a+1,a+n+1,cmp1);
			int sum=0;
			for(int i=1; i<=n; i++) sum+=a[i].v1;
			printf("%d\n",sum);
			continue;
		}
		dfs(1,0,0,0,0);
		printf("%d\n",Max1);
	}
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int INF=1e5+10;
int t,n;
bool flag1[INF],flag2[INF],flag3[INF];
struct Node{
	int v1,v2,v3,id;
}a[INF];
bool cmp1(Node x,Node y){
	return x.v1>y.v1;
}
bool cmp2(Node x,Node y){
	return x.v2>y.v2;
}
bool cmp3(Node x,Node y){
	return x.v3>y.v3;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			 scanf("%d %d %d",&a[i].v1,&a[i].v2,&a[i].v3);
			 a[i].id=i;
		 }
		sort(a+1,a+n+1,cmp1);
		for(int i=1; i<=n/2; i++)
			flag1[a[i].id]=true;
		sort(a+1,a+n+1,cmp2);
		for(int i=1; i<=n/2; i++)
			flag2[a[i].id]=true;
		sort(a+1,a+n+1,cmp3);
		for(int i=1; i<=n/2; i++)
			flag3[a[i].id]=true;
		int t1=n/2,t2=n/2,t3=n/2;
		for(int i=1; i<=n; i++){
			if(flag1[a[i].id]==true&&flag2[a[i].id]==true){
				if(a[a[i].id].v1>=a[a[i].id].v2) t2--,flag2[a[i].id]=false;
				if(a[a[i].id].v2>a[a[i].id].v1) t1--,flag1[a[i].id]=false;
			}
		}
		int sum=0;
		for(int i=1; i<=n; i++){
			if(flag1[a[i].id==true) sum+=a[a[i].id].v1;
			else if(flag2[a[i].id]==true) sum+=a[a[i].id].v2;
			else if(flag3[a[i].id]==true) sum+=a[a[i].id].v3;
		}
		printf("%d\n",sum);
	}
	return 0;
}
*/
