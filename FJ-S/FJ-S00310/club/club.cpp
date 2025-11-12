#include<bits/stdc++.h>
using namespace std;
struct Phigros{
	int man;
	int likes;
}a[100005],b[100005],c[100005];
int ma[100005],mb[100005],mc[100005];
bool cmp(Phigros x,Phigros y){
	if(x.likes==y.likes){
		if(ma[x.man]==ma[y.man]){
			if(mb[x.man]-mb[y.man]+mc[x.man]-mc[y.man]==0){
				return abs(mb[x.man]-mc[x.man])-abs(mb[y.man]-mc[y.man])<0;
			}
			return mb[x.man]-mb[y.man]+mc[x.man]-mc[y.man]<0;
		}
		else if(mb[x.man]==mb[y.man]){
			if(ma[x.man]-ma[y.man]+mc[x.man]-mc[y.man]==0){
				return abs(ma[x.man]-mc[x.man])-abs(ma[y.man]-mc[y.man])<0;
			}
			return ma[x.man]-ma[y.man]+mc[x.man]-mc[y.man]<0;
		}
		else{
			if(mb[x.man]-mb[y.man]+ma[x.man]-ma[y.man]==0){
				return abs(mb[x.man]-ma[x.man])-abs(mb[y.man]-ma[y.man])<0;
			}
			return ma[x.man]-ma[y.man]+mb[x.man]-mb[y.man]<0;
		}
	}
	return x.likes>y.likes;
}
int t,n,ai,bi,ci;
bool x[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].likes,&b[i].likes,&c[i].likes);
			ma[i]=a[i].likes;
			mb[i]=b[i].likes;
			mc[i]=c[i].likes;
			x[i]=false;
			a[i].man=i;
			b[i].man=i;
			c[i].man=i;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		ai=1;
		bi=1;
		ci=1;
		int an=0,bn=0,cn=0;
		long long ans=0;
		for(int i=1;i<=n;i++){
			while(x[a[ai].man])ai++;
			while(x[b[bi].man])bi++;
			while(x[c[ci].man])ci++;
			if(an==n/2)a[ai].likes=-1;
			if(bn==n/2)b[bi].likes=-1;
			if(cn==n/2)c[cn].likes=-1;
			if(a[ai].likes>=b[bi].likes&&a[ai].likes>=c[ci].likes){
				ans+=a[ai].likes;
				x[a[ai].man]=true;
				ai++;
				an++;
			}
			else if(b[bi].likes>=a[ai].likes&&b[bi].likes>=c[ci].likes){
				ans+=b[bi].likes;
				x[b[bi].man]=true;
				bi++;
				bn++;
			}
			else{
				ans+=c[ci].likes;
				x[c[ci].man]=true;
				ci++;
				cn++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
