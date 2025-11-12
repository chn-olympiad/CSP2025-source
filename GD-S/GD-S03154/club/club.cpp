#include<bits/stdc++.h>
using namespace std;
int aa[5],T;
struct asd{
	int x;
	int y;
	int z;
}a[100005];
int n;
long long sum,ma;
bool cmp1(asd b1,asd b2){
	return (b1.x-max(b1.y,b1.z))<(b2.x-max(b2.y,b2.z));
}
bool cmp2(asd b1,asd b2){
	return (b1.y-max(b1.x,b1.z))<(b2.y-max(b2.x,b2.z));
}
bool cmp3(asd b1,asd b2){
	return (b1.z-max(b1.x,b1.y))<(b2.z-max(b2.y,b2.x));
}
bool cmp4(asd b1,asd b2){
	return max({b1.x,b1.y,b1.z})>max({b2.x,b2.y,b2.z});
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			sum+=a[i].x;
		}
		for(int i=1;i<=n/2;i++){
			sum-=(a[i].x-max(a[i].y,a[i].z));
		}
		ma=max(ma,sum);
		sum=0;
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n;i++){
			sum+=a[i].y;
		}
		for(int i=1;i<=n/2;i++){
			sum-=(a[i].y-max(a[i].x,a[i].z));
		}
		ma=max(ma,sum);
		sum=0;
		sort(a+1,a+1+n,cmp3);
		for(int i=1;i<=n;i++){
			sum+=a[i].z;
		}
		for(int i=1;i<=n/2;i++){
			sum-=(a[i].z-max(a[i].y,a[i].x));
		}
		ma=max(ma,sum);
		sum=0;
		aa[1]=n/2;
		aa[2]=n/2;
		aa[3]=n/2;
		for(int i=1;i<=n;i++){
			sum+=max({a[i].x,a[i].y,a[i].z});
			if(max({a[i].x,a[i].y,a[i].z})==a[i].x)
			aa[1]--;
			else if(max({a[i].x,a[i].y,a[i].z})==a[i].y)
			aa[2]--;
			else if(max({a[i].x,a[i].y,a[i].z})==a[i].z)
			aa[3]--;
			if(aa[1]==0){
				for(int t=i+1;t<=n;t++)
				a[t].x=-1;
				aa[1]=114514;
			}
			else if(aa[2]==0){
				for(int t=i+1;t<=n;t++)
				a[t].y=-1;
				aa[2]=114514;
			}
			else if(aa[3]==0){
				for(int t=i+1;t<=n;t++)
				a[t].z=-1;
				aa[3]=114514;
			}
		}
		ma=max(sum,ma);
		sum=0;
		printf("%lld\n",ma);
		ma=0;
	}
	return 0;
}

