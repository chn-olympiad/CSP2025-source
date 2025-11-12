#include<bits/stdc++.h>
using namespace std;
struct U{int da , id , idx ;}sum[100005] ;
struct S{int a1 , a2 , a3 ;}a[100005] ;
int T , n , ans ;
bool flagA=1 , flagB=1 ;
bool cmp(S x , S y){
	if(x.a1>y.a1)return 1;
	else if(x.a1==y.a1)
		if(x.a2>y.a2)return 1;
		else if(x.a2==y.a2)
			if(x.a3>y.a3)return 1;
	return 0;
}
void dfs(int i , int t1 , int t2 , int t3 , int cnt){
	if(max({t1,t2,t3})-min({t1,t2,t3})>n/2)return;
	if(i==n+1){
		ans=max(ans,cnt);
		return;
	}
	dfs(i+1,t1+1,t2,t3,cnt+a[i].a1);
	dfs(i+1,t1,t2+1,t3,cnt+a[i].a2);
	dfs(i+1,t1,t2,t3+1,cnt+a[i].a3);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		// int sum1=0 , sum2=0 , sum3=0 ;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].a1,&a[i].a2,&a[i].a3);
			if(a[i].a2!=0||a[i].a3!=0)flagA=0;
			if(a[i].a3!=0)flagB=0;
		}
		dfs(1,0,0,0,0);
		sort(a+1,a+1+n,cmp);
		// if(flagA){
		// 	// int tmp ;
		// 	for(int i=1;i-(n-i)/2<n/2;i++){
		// 		ans+=a[i].a1;
		// 	}
		// }
		printf("%d\n",ans);
	}
	return 0;
}
//MJW保佑我CSPrp++
//MJWYYDS
//CSPrp+++
//苗晋玮保佑我rp++
//rp+=INF
//rp++