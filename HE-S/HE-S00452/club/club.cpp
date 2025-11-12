#include<cstdio>
#include<algorithm>

const int N=1e5+1*5;
int t,n;
struct point{int x,y,z;}a[N],b2[N],b3[N];
int max(int x,int y){return x>y?x:y;}
bool cmp1(point x,point y){return max(x.y-x.x,x.z-x.x)>max(y.y-y.x,y.z-y.x);}
bool cmp2(point x,point y){return max(x.x-x.y,x.z-x.y)>max(y.x-y.y,y.z-y.y);}
bool cmp3(point x,point y){return max(x.x-x.z,x.y-x.z)>max(y.x-y.z,y.y-y.z);}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		long long ans=0;
		int c[4]={0,0,0,0};
		for(int i=1;i<=n;i++,c[1]++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),ans+=a[i].x;
		std::sort(a+1,a+1+n,cmp1);
		int cnt=0,k2=0,k3=0;
		for(int i=1;i<=n;i++,c[1]--){
			if(c[1]-cnt<=n/2&&a[i].y-a[i].x<=0&&a[i].z-a[i].x<=0) break;
			if(a[i].y>a[i].z) c[2]++,ans+=a[i].y-a[i].x,b2[++k2]=a[i];
			if(a[i].y<a[i].z) c[3]++,ans+=a[i].z-a[i].x,b3[++k3]=a[i];
			if(a[i].y==a[i].z) ans+=a[i].y-a[i].x,cnt++;
		}
		if(c[2]>n/2) {std::sort(b2+1,b2+1+k2,cmp2); for(int i=1;c[2]>n/2;i++,c[2]--) ans+=max(b2[i].x,b2[i].z)-b2[i].y;}
		if(c[3]>n/2) {std::sort(b3+1,b3+1+k3,cmp3); for(int i=1;c[3]>n/2;i++,c[3]--) ans+=max(b3[i].x,b3[i].y)-b3[i].z;}
		printf("%lld\n",ans);
	}
	return 0;
}
