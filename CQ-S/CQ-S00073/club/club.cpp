#include<bits/stdc++.h>
using namespace std;
struct xs{
	int sa,sd,cw;
} xl[100010];
int t,n;
int cmp(xs x,xs y){
	if(x.sd==y.sd) return x.cw>y.cw;
	return x.sd<y.sd;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++){
			int rk1=-1,rkp=0,rk2=-1;
			for(int j=1;j<=3;j++){
				int a=0;
				scanf("%d",&a);
				if(a>rk1){
					rk2=rk1;
					rk1=a;
					rkp=j;
				}
				else if(a>rk2) rk2=a;
			}
			xl[i]={rk1,rkp,rk1-rk2};
			ans+=rk1;
		}
		sort(xl+1,xl+n+1,cmp);
		int l=0;
		for(int i=1;i<=n;i++){
			if(xl[i].sd!=xl[i-1].sd) l=i;
			if(i-l+1>n/2) ans-=xl[i].cw;
		}
		printf("%d\n",ans);
	}
	return 0;
}
//14:47¹ıT1 
