#include "iostream"
#include "cstdio"
#include "algorithm"
#include "string"
#include "cstring"
using namespace std;
int t,n;
struct Node {
	long long x,y,z,ss;
}a[100005],b[100005],c[100005],m[100005];
bool operator <(const Node &x,const Node &y){
	return x.ss>y.ss;
}
inline long long mx(long long x,long long y){
	return x>y?x:y;
}
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	scanf ("%d",&t);
	while (t--){
		scanf ("%d",&n);
		int tat=0,tbt=0,tct=0;
		memset (m,0,sizeof(m));
		memset (a,0,sizeof(a));
		memset (b,0,sizeof(b));
		memset (c,0,sizeof(c));
		for (int i=1;i<=n;i++){
			scanf ("%lld %lld %lld",&m[i].x,&m[i].y,&m[i].z);
			if (m[i].x>=m[i].y && m[i].x>=m[i].z){
				a[++tat].x=m[i].x;
				a[tat].y=m[i].y;
				a[tat].z=m[i].z;
			}
			else if (m[i].y>=m[i].x && m[i].y>=m[i].z){
				b[++tbt].x=m[i].x;
				b[tbt].y=m[i].y;
				b[tbt].z=m[i].z;
			}
			else{
				c[++tct].x=m[i].x;
				c[tct].y=m[i].y;
				c[tct].z=m[i].z;
			}
		}
		if (tat<=n/2 && tbt<=n/2 && tct<=n/2){
			long long ans=0;
			for (int i=1;i<=tat;i++) ans+=a[i].x;
			for (int i=1;i<=tbt;i++) ans+=b[i].y;
			for (int i=1;i<=tct;i++) ans+=c[i].z;
			printf ("%lld\n",ans);
			continue;
		}
		if (tat>n/2){
			long long ans1=0,ans2=0;
			for (int i=1;i<=tat;i++) a[i].ss=a[i].x-a[i].y;
			sort (a+1,a+1+tat);
			for (int i=1;i<=n/2;i++) ans1+=a[i].x;
			for (int i=n/2+1;i<=tat;i++){
				ans1+=a[i].y;
			}
			for (int i=1;i<=tbt;i++) ans1+=b[i].y;
			for (int i=1;i<=tct;i++) ans1+=c[i].z;
			
			for (int i=1;i<=tat;i++) a[i].ss=a[i].x-a[i].z;
			sort (a+1,a+1+tat);
			for (int i=1;i<=n/2;i++) ans2+=a[i].x;
			for (int i=n/2+1;i<=tat;i++){
				ans2+=a[i].z;
			}
			for (int i=1;i<=tbt;i++) ans2+=b[i].y;
			for (int i=1;i<=tct;i++) ans2+=c[i].z;
			printf ("%lld\n",mx(ans1,ans2));
		}
		if (tbt>n/2){
			long long ans1=0,ans2=0;
			for (int i=1;i<=tbt;i++) b[i].ss=b[i].y-b[i].x;
			sort (b+1,b+1+tbt);
			for (int i=1;i<=n/2;i++) ans1+=b[i].y;
			for (int i=n/2+1;i<=tbt;i++){
				ans1+=b[i].x;
			}
			for (int i=1;i<=tat;i++) ans1+=a[i].x;
			for (int i=1;i<=tct;i++) ans1+=c[i].z;
			
			for (int i=1;i<=tbt;i++) b[i].ss=b[i].y-b[i].z;
			sort (b+1,b+1+tbt);
			for (int i=1;i<=n/2;i++) ans2+=b[i].y;
			for (int i=n/2+1;i<=tbt;i++){
				ans2+=b[i].z;
			}
			for (int i=1;i<=tat;i++) ans2+=a[i].x;
			for (int i=1;i<=tct;i++) ans2+=c[i].z;
			printf ("%lld\n",mx(ans1,ans2));
		}
		if (tct>n/2){
			long long ans1=0,ans2=0;
			for (int i=1;i<=tct;i++) c[i].ss=c[i].z-c[i].x;
			sort (c+1,c+1+tct);
			for (int i=1;i<=n/2;i++) ans1+=c[i].z;
			for (int i=n/2+1;i<=tct;i++){
				ans1+=c[i].x;
			}
			for (int i=1;i<=tat;i++) ans1+=a[i].x;
			for (int i=1;i<=tbt;i++) ans1+=b[i].y;
			
			for (int i=1;i<=tct;i++) c[i].ss=c[i].z-c[i].y;
			sort (c+1,c+1+tct);
			for (int i=1;i<=n/2;i++) ans2+=c[i].z;
			for (int i=n/2+1;i<=tct;i++){
				ans2+=c[i].y;
			}
			for (int i=1;i<=tat;i++) ans2+=a[i].x;
			for (int i=1;i<=tbt;i++) ans2+=b[i].y;
			printf ("%lld\n",mx(ans1,ans2));
		}
	}
	return 0;
}
