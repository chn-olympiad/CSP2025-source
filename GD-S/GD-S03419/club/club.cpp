#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct sgs{
	int x,y,z;
}a[N];
struct px{
	int l,r,cha;
}b[N];
int t,n,q;
int xx,yy,zz,cnt;
long long ans,s[N];
bool cmp(px a,px b){
	return a.cha>b.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0,q=0;
		xx=0,yy=0,zz=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			if(a[i].x>=max(a[i].y,a[i].z)) xx++;
			if(a[i].y>=max(a[i].x,a[i].z)) yy++;
			if(a[i].z>=max(a[i].y,a[i].x)) zz++;
		}
		if(yy>xx){
			xx=yy;
			for(int i=1;i<=n;i++) swap(a[i].x,a[i].y);
		}
		if(zz>xx){
			for(int i=1;i<=n;i++) swap(a[i].x,a[i].z);
		}
		for(int i=1;i<=n;i++){
			b[i].l=a[i].x;
			b[i].r=max(a[i].y,a[i].z);
			b[i].cha=b[i].l-b[i].r;
		}
		sort(b+1,b+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(b[i].l>b[i].r){
				if(q>=n/2){
					ans+=b[i].r;
				}
				else{
					ans+=b[i].l;
					q++;	
				}
			}
			else{
				ans+=b[i].r;
			}
		}
		s[++cnt]=ans;
	}
	for(int i=1;i<=cnt;i++) printf("%lld\n",s[i]);
	return 0;
}

