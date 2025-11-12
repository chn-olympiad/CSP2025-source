#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct awa{
	ll x,bh;
}c[200010][4];
struct qwq{
	ll x,li,bh1,bh2;
}cz[200010];//这是差值不是chenzhe
int tt;
bool cmp(qwq a,qwq b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&tt);
	while(tt--){
		memset(c,0,sizeof(c));
		memset(cz,0,sizeof(cz));
		ll n,ans=0;
		scanf("%d",&n);
		for(ll i=1;i<=n;i++){
			scanf("%d%d%d",&c[i][1].x,&c[i][2].x,&c[i][3].x);
			c[i][1].bh=1,c[i][2].bh=2,c[i][3].bh=3;
			if(c[i][1].x<c[i][2].x)swap(c[i][1],c[i][2]);
			if(c[i][2].x<c[i][3].x)swap(c[i][2],c[i][3]);
			if(c[i][1].x<c[i][2].x)swap(c[i][1],c[i][2]);
		}
		
		for(int i=1;i<=n;i++){
			cz[i].x=c[i][1].x-c[i][2].x;
			cz[i].bh1=c[i][1].bh,cz[i].bh2=c[i][2].bh;
			cz[i].li=i;
		}
		sort(cz+1,cz+n+1,cmp);
		ll p[4]={0};
		for(ll i=1;i<=n;i++){
			if(p[cz[i].bh1]+1>n/2){
				p[cz[i].bh2]++;
				ans+=c[cz[i].li][2].x;
			}
			else{
				p[cz[i].bh1]++;
				ans+=c[cz[i].li][1].x;
			}
		}
		printf("%d\n",ans);
		
	}
	
return 0;}
//这个键盘好难用 
/*
if(p[c[i][1].bh]+1>n/2){
				p[c[i][2].bh]++;
				ans+=c[i][2].x;
			}
			else{
				p[c[i][1].bh]++;
				ans+=c[i][1].x;
			}
*/
