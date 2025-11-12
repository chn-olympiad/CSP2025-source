#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN=100501;
int t,n,a[MN][3],cnt[3],ans,bj=-1,cntb;
struct Edge{int w,d,d1,w1;}m[MN],b[MN];
int cmp(Edge x,Edge y){
	return (x.w-x.w1)>(y.w-y.w1);
}void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&a[i][j]);
			if(m[i].w<=a[i][j]){
				int dd=m[i].d,ww=m[i].w;
				m[i]=(Edge){a[i][j],j,dd,ww};
			}else if(m[i].w1<=a[i][j]){
				m[i].d1=j,m[i].w1=a[i][j];
			}
		}
	}for(int i=1;i<=n;i++){
		if(cnt[m[i].d]>=n/2){bj=m[i].d;break;}
		else cnt[m[i].d]++,ans+=m[i].w;
	}if(bj!=-1){ans=0;
		for(int i=1;i<=n;i++){
			if(m[i].d==bj)b[++cntb]=m[i];
			else ans+=m[i].w;
		}sort(b+1,b+1+cntb,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=b[i].w;
		}for(int i=n/2+1;i<=cntb;i++){
			ans+=b[i].w1;
		}
	}printf("%lld\n",ans);
	bj=-1;for(int i=1;i<=n;i++){
		b[i]=m[i]=(Edge){0,0,0,0};
	}cnt[0]=cnt[1]=cnt[2]=ans=cntb=0;
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
