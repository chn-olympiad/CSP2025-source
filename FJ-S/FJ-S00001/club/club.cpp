#include<bits/stdc++.h>
using namespace std;
inline int read(){
	register char c=getchar();
	register int x=0;
	for(;(c<48)||(c>57);c=getchar());
	for(;(47<c)&&(c<58);c=getchar()){
		x=(x<<1)+(x<<3)+c-48;
	}
	return x;
}
#define ll long long
int a[100010][3],mx[100010],cnt[3];
struct node{
	int x,y,dt;
}b[100010];
inline bool cmp(node xx,node yy){
	return xx.dt>yy.dt;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read(),n,wz;
	ll ans;
	bool fl;
	while(T--){
		n=read();
		cnt[0]=cnt[1]=cnt[2]=0;
		ans=0;
		for(register int i=1;i<=n;++i){
			mx[i]=-1;
			for(register int j=0;j<=2;++j){
				a[i][j]=read();
				mx[i]=max(mx[i],a[i][j]);
			}
			wz=0;
			for(register int j=0;j<=2;++j){
				if(a[i][j]==mx[i]){
					wz=j;
				}
			}
			++cnt[wz];
		}
		wz=0;
		fl=true;
		for(register int j=0;j<=2;++j){
			if(cnt[j]>(n/2)){
				fl=false;
				wz=j;
			}
		}
		if(fl){
			ans=0;
			for(register int i=1;i<=n;++i){
				ans+=mx[i];
			}
		}
		else{
			for(register int i=1;i<=n;++i){
				b[i].x=a[i][wz];
				b[i].y=0;
				for(register int j=0;j<=2;++j){
					if(j!=wz){
						b[i].y=max(b[i].y,a[i][j]);
					}
				}
				b[i].dt=b[i].x-b[i].y;
			}
			sort(b+1,b+n+1,cmp);
			ans=0;
			for(register int i=1;i<=n/2;++i){
				ans+=b[i].x;
			}
			for(register int i=n/2+1;i<=n;++i){
				ans+=b[i].y;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
