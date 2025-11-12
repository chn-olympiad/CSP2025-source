#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int t,n;
struct node{
	long long x,y,z;
}a[100001];
bool cmp1(node p,node q){
	if(p.x-max(p.y,p.z)!=q.x-max(q.y,q.z)){
		return p.x-max(p.y,p.z)>q.x-max(q.y,q.z);
	}
	if(max(p.y,p.z)!=max(q.y,q.z))return max(p.y,p.z)<max(q.y,q.z);
	return p.x>q.x;
}
bool cmp2(node p,node q){
	if(p.y-max(p.x,p.z)!=q.y-max(q.x,q.z)){
		return p.y-max(p.x,p.z)>q.y-max(q.x,q.z);
	}
	if(max(p.x,p.z)!=max(q.x,q.z))return max(p.x,p.z)<max(q.x,q.z);
	return p.y>q.y;
}
bool cmp3(node p,node q){
	if(p.z-max(p.x,p.y)!=q.z-max(q.x,q.y)){
		return p.z-max(p.x,p.y)>q.z-max(q.x,q.y);
	}
	if(max(p.x,p.y)!=max(q.x,q.y))return max(p.x,p.y)<max(q.x,q.y);
	return p.z>q.z;
}
int h;
void dfs(int x,int y,int z,int t,int ss){
	if(t==n+1){
		h=max(h,ss);
		return ;
	}
	for(int i=0;i<=2;i++){
		if(x<n/2)dfs(x+1,y,z,t+1,ss+a[t].x);
		if(y<n/2)dfs(x,y+1,z,t+1,ss+a[t].y);
		if(z<n/2)dfs(x,y,z+1,t+1,ss+a[t].z);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		long long ans1=0,ans2=0,ans3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		}
		if(n>4){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(i<=n/2)ans1+=a[i].x;
				else ans1+=max(a[i].y,a[i].z);
			}
			sort(a+1,a+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(i<=n/2)ans2+=a[i].y;
				else ans2+=max(a[i].x,a[i].z);
			}
			sort(a+1,a+1+n,cmp3);
			for(int i=1;i<=n;i++){
				if(i<=n/2)ans3+=a[i].z;
				else ans3+=max(a[i].x,a[i].y);
			}
			printf("%lld\n",max(ans1,max(ans2,ans3)));
		}else{
			h=0;
			dfs(0,0,0,1,0);
			printf("%d\n",h);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//RP++
