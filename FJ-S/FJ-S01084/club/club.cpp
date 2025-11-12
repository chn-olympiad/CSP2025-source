#include<bits/stdc++.h>
using namespace std;
int T,n;
const int N=1e5+10;
int aa,bb,cc,ab,ac,bc,abc;
long long ans=0;
struct node{
	int x,y,z,m,c;
}a[N];
int ah[N],bh[N],ch[N];
int f(int b){
	if(a[b].x==a[b].y&&a[b].z==a[b].y){
		a[b].m=7;
		abc++;
		ans+=a[b].x;
		return 0;
	}
	if(a[b].x>a[b].z){
		if(a[b].x>a[b].y){
			a[b].m=1;
			a[b].c=a[b].x-max(a[b].y,a[b].z);
			aa++;
			ans+=a[b].x;
			return 1;
		}
		if(a[b].x==a[b].y){
			a[b].m=4;
			ab++;
			ans+=a[b].x;
			return 0;
		}
	}
	if(a[b].y>a[b].x){
		if(a[b].y>a[b].z){
			a[b].m=2;
			a[b].c=a[b].y-max(a[b].z,a[b].x);
			bb++;
			ans+=a[b].y;
			return 1;
		}
		if(a[b].y==a[b].z){
			a[b].m=5;
			bc++;
			ans+=a[b].y;
			return 0;
		}
	}
	if(a[b].z>a[b].y){
		if(a[b].z>a[b].x){
			a[b].m=3;
			a[b].c=a[b].z-max(a[b].y,a[b].x);
			cc++;
			ans+=a[b].z;
			return 1;
		}
		if(a[b].x==a[b].z){
			a[b].m=6;
			ac++;
			ans+=a[b].x;
			return 0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		aa=ab=ac=bc=bb=cc=0;
		int ta=0,tb=0,tc=0;
		ans=0;
		for(int i=1;i<=n;i++){
			int maxn=0;
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
			f(i);
			if(a[i].m==1){
				ah[++ta]=a[i].c;
			}
			else if(a[i].m==2){
				bh[++tb]=a[i].c;
			}
			else if(a[i].m==3){
				ch[++tc]=a[i].c;
			}
		}
		int maxx=n/2;
		if(aa>maxx){
			sort(ah+1,ah+1+ta);
			for(int i=1;i<=aa-maxx;i++){
				ans-=ah[i];
			}
			printf("%lld\n",ans);
		}
		else if(bb>maxx){
			sort(bh+1,bh+1+tb);
			for(int i=1;i<=bb-maxx;i++){
				ans-=bh[i];
			}
			printf("%lld\n",ans);
		}
		else if(cc>maxx){
			sort(ch+1,ch+1+tc);
			for(int i=1;i<=cc-maxx;i++){
				ans-=ch[i];
			}
			printf("%lld\n",ans);
		}
		else printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
