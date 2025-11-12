#include<bits/stdc++.h>
using namespace std;
int t,n;
long long tot;
struct person{
	int x,y,z;
}a[100005];
void pprint1(){
	long long ans=0;
	for(int i=n/2+1;i<=n;i++){
		ans+=max(a[i].y,a[i].z);
	}printf("%lld\n",ans+tot);
}
void pprint2(){
	long long ans=0;
	for(int i=n/2+1;i<=n;i++){
		ans+=max(a[i].x,a[i].z);
	}printf("%lld\n",ans+tot);
}
void pprint3(){
	long long ans=0;
	for(int i=n/2+1;i<=n;i++){
		ans+=max(a[i].y,a[i].x);
	}printf("%lld\n",ans+tot);
}
void pprint(){
	printf("%lld\n",tot);
}
bool cmp1(person a,person b){
	if(a.x==b.x){
		return max(a.y,a.z)<max(b.y,b.z);
	}
	return a.x>b.x;
}
bool cmp2(person a,person b){
	if(a.y==b.y){
		return max(a.x,a.z)<max(b.x,b.z);
	}
	return a.y>b.y;
}
bool cmp3(person a,person b){
	if(a.z==b.z){
		return max(a.y,a.x)<max(b.y,b.x);
	}
	return a.z>b.z;
}
bool solve1(){
	sort(a+1,a+1+n,cmp1);
	return a[n/2+1].x>max(a[n/2+1].z,a[n/2+1].y);
}
bool solve2(){
	sort(a+1,a+1+n,cmp2);
//	for(int i=1;i<=n;i++){
//		cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<'\n';
//	}
	return a[n/2+1].y>max(a[n/2+1].x,a[n/2+1].z);
}
bool solve3(){
	sort(a+1,a+1+n,cmp3);
	return a[n/2+1].z>max(a[n/2+1].x,a[n/2+1].y);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		tot=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			long long ls=max(a[i].x,max(a[i].y,a[i].z));
			tot+=ls;
			a[i].x-=ls;
			a[i].y-=ls;
			a[i].z-=ls;
		}
		if(solve1()){
			pprint1();
			continue;
		}
		if(solve2()){
			pprint2();
			continue;
		}
		if(solve3()){
			pprint3();
			continue;
		}
		pprint();
	}
	return 0;
} 
