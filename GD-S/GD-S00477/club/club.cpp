#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long t,n,tag[4],ans,m,q;
struct st{
	long long x,y,z,maxx,minn,i,ii;
}a[maxn];
bool cmp(st x,st y){
	return (x.maxx-x.ii)<(y.maxx-y.ii);
}
int main(){
	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(tag,0,sizeof(tag));
		scanf("%lld",&n);
		m=n/2;
		ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
			a[i].maxx=max(a[i].x,a[i].y);
			a[i].maxx=max(a[i].maxx,a[i].z);
			a[i].minn=min(a[i].x,a[i].y);
			a[i].minn=min(a[i].minn,a[i].z);
			if(a[i].maxx==a[i].x){
				tag[1]++;ans+=a[i].x;a[i].i=1;
				if(a[i].minn==a[i].x) a[i].ii=a[i].x;
				else if(a[i].minn==a[i].y) a[i].ii=a[i].z;
				else if(a[i].minn==a[i].z) a[i].ii=a[i].y;
			}
			else if(a[i].maxx==a[i].y) {
				tag[2]++;ans+=a[i].y;a[i].i=2;
				if(a[i].minn==a[i].y) a[i].ii=a[i].y;
				else if(a[i].minn==a[i].x) a[i].ii=a[i].z;
				else if(a[i].minn==a[i].z) a[i].ii=a[i].x;
			}
			else if(a[i].maxx==a[i].z){
			 	tag[3]++;ans+=a[i].z;a[i].i=3;
			 	if(a[i].minn==a[i].z) a[i].ii=a[i].z;
				else if(a[i].minn==a[i].x) a[i].ii=a[i].y;
				else if(a[i].minn==a[i].y) a[i].ii=a[i].x;
			}
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(tag[a[i].i]>m){
				ans-=(a[i].maxx-a[i].ii);
				if(a[i].x==a[i].y&&a[i].x==a[i].z&&a[i].x==a[i].ii){
					if(tag[1]<=tag[2]&&tag[1]<=tag[3]) q=1;
					else if(tag[2]<=tag[1]&&tag[2]<=tag[3]) q=2;
					else if(tag[3]<=tag[1]&&tag[3]<=tag[2]) q=3;
				}
				else if(a[i].x==a[i].y&&a[i].x==a[i].ii){
					if(tag[1]<=tag[2]) q=1;
					else q=2;
				}
				else if(a[i].x==a[i].z&&a[i].x==a[i].ii){
					if(tag[1]<=tag[3]) q=1;
					else q=3;
				}
				else if(a[i].z==a[i].y&&a[i].z==a[i].ii){
					if(tag[3]<=tag[2]) q=3;
					else q=2;
				}
				else if(a[i].x==a[i].ii) q=1;
				else if(a[i].y==a[i].ii) q=2;
				else if(a[i].z==a[i].ii) q=3;
				tag[q]++;tag[a[i].i]--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 

