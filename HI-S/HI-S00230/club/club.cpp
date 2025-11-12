#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct node{
	int x,y,z;
}a[N],b[N];
int n;
long long f[101010];
bool cmp(node a1,node b1){
	if(a1.x!=b1.x) return a1.x>b1.x;
	if(a1.y!=b1.y) return a1.y>b1.y;
	return a1.z>b1.z;
}
bool cmp1(node a1,node b1){
	if(a1.y!=b1.y) return a1.y>b1.y;
	if(a1.x!=b1.x) return a1.x>b1.x;
	return a1.z>b1.z;
}
bool cmp2(node a1,node b1){
	if(a1.z!=b1.z) return a1.z>b1.z;
	if(a1.y!=b1.y) return a1.y>b1.y;
	return a1.x>b1.x;
}
long long work(int x,int pos){
	memset(f,0,sizeof f);
	if(x==1){
		sort(a+1,a+n+1,cmp);
		for(int i=pos;i<=n;i++){
			f[i]=max(f[i-1]+a[i].y,f[i-1]+a[i].z);
		}
//		printf("work 1:%lld\n",ret);
	}
	if(x==2){
		sort(a+1,a+n+1,cmp1);
		for(int i=pos;i<=n;i++){
			f[i]=max(f[i-1]+a[i].x,f[i-1]+a[i].z);
		}
//		printf("work 2:%lld\n",ret);
	}
	if(x==3){
		sort(a+1,a+n+1,cmp2);
		for(int i=pos;i<=n;i++){
			f[i]=max(f[i-1]+a[i].x,f[i-1]+a[i].y);
		}
//		printf("work 3:%lld\n",ret);
	}
	return f[n];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		long long ans=0,ans1=0,ans2=0;
		long long pt=0;
		for(int i=1;i<=n/2;i++){
			sort(a+1,a+n+1,cmp);
			ans+=a[i].x;
			sort(a+1,a+n+1,cmp1);
			ans1+=a[i].y;
			sort(a+1,a+n+1,cmp2);
			ans2+=a[i].z;
			long long get=work(1,i+1);
			long long get1=work(2,i+1);
			long long get2=work(3,i+1);
			pt=max(pt,max(get+ans,max(get1+ans1,get2+ans2)));
//			printf("%lld ",pt);
		}
		printf("%lld\n",pt);
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


1
6
5 7 4
4 2 3
3 5 6
3 6 7
3 8 5
3 3 2
*/
