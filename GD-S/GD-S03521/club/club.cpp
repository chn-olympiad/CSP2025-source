#include<bits/stdc++.h>
using namespace std;
int T,n,m,ra,rb,rc,a[100010],b[100010],c[100010],ans;
struct stua{int bx,nx;}va[100010];
bool cmpa(stua pre,stua nxt){return pre.bx-pre.nx<nxt.bx-nxt.nx;}
struct stub{int bx,nx;}vb[100010];
bool cmpb(stub pre,stub nxt){return pre.bx-pre.nx<nxt.bx-nxt.nx;}
struct stuc{int bx,nx;}vc[100010];
bool cmpc(stuc pre,stuc nxt){return pre.bx-pre.nx<nxt.bx-nxt.nx;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;m=n/2;ra=0;rb=0;rc=0;ans=0;
		for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
		for(int i=1;i<=n;i++){
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ra++;va[ra].bx=a[i];ans+=a[i];
				if(b[i]>=c[i])va[ra].nx=b[i];
				else va[ra].nx=c[i];
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				rb++;vb[rb].bx=b[i];ans+=b[i];
				if(a[i]>=c[i])vb[rb].nx=a[i];
				else vb[rb].nx=c[i];
			}
			else if(c[i]>=b[i]&&c[i]>=a[i]){
				rc++;vc[rc].bx=c[i];ans+=c[i];
				if(b[i]>=a[i])vc[rc].nx=b[i];
				else vc[rc].nx=a[i];
			}
		}
		if(ra>m){
			sort(va+1,va+1+ra,cmpa);
			for(int i=1;i<=ra-m;i++){ans-=va[i].bx;ans+=va[i].nx;}
		}
		else if(rb>m){
			sort(vb+1,vb+1+rb,cmpb);
			for(int i=1;i<=rb-m;i++){ans-=vb[i].bx;ans+=vb[i].nx;}
		}
		else if(rc>m){
			sort(vc+1,vc+1+rc,cmpc);
			for(int i=1;i<=rc-m;i++){ans-=vc[i].bx;ans+=vc[i].nx;}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
