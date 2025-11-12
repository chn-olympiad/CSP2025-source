#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<climits>
#include<queue>
#define ll long long
using namespace std;
const int N=2e5+86;
ll n,m;
priority_queue<pair<ll,ll> > q1,q2,q3;
struct T{
	ll xx,yy,zz;
};
T a[N];
ll cnt1,cnt2,cnt3;
pair<ll,ll> xk,yk,zk;
ll tot=0;
bool lx[N],fx,fy,fz;
ll ffx(ll lss,ll wzc,ll zqf){
	return max(lss,max(wzc,zqf));
}
ll ans,maxs;
ll ansk[N];
void dfs(int x,int y,int z,ll val,int cntx,int cnty,int cntz,ll tot){
	if(ansk[tot]>tot) return;
	ansk[tot]=max(ansk[tot],tot);
	if(tot==n){
		ans=max(ans,val);
		return;
	}
	if(x>n) return;
	if(y>n) return;
	if(z>n) return;
	if(cntx<n/2&&!lx[x]){
		lx[x]=1;
		val+=a[x].xx;
		dfs(x+1,y,z,val,cntx+1,cnty,cntz,tot+1);
		lx[x]=0;
		val-=a[x].xx;
//		dfs(x+1,y,z,val+a[x].xx,cntx+1,cnty,cntz,tot+1);
	}
	if(cnty<n/2&&!lx[y]){
//		if(val+a[y].yy)
		lx[y]=1;
		val+=a[y].yy;
		dfs(x,y+1,z,val,cntx,cnty+1,cntz,tot+1);
		val-=a[y].yy;
		lx[y]=0;
//		dfs(x,y+1,z,val+a[y].yy,cntx,cnty+1,cntz,tot+1);
	}
	if(cntz<n/2&&!lx[z]){
		val+=a[z].zz;
		lx[z]=1;
		dfs(x,y,z+1,val,cntx,cnty,cntz+1,tot+1);
		val-=a[z].zz;
		lx[z]=0;
//		dfs(x,y,z+1,val+a[z].zz,cntx,cnty,cntz+1,tot+1);
	} 
	dfs(x+1,y,z,val,cntx,cnty,cntz,tot);
	dfs(x,y+1,z,val,cntx,cnty,cntz,tot);
	dfs(x,y,z+1,val,cntx,cnty,cntz,tot);
}
int main(){
	ll t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		memset(lx,0,sizeof(lx));
		memset(ansk,0,sizeof(ansk));
		maxs=0,ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].xx,&a[i].yy,&a[i].zz);
			q1.push(make_pair(a[i].xx,i)),q2.push(make_pair(a[i].yy,i)),q3.push(make_pair(a[i].zz,i));
		}
		if(n<=30) {
			dfs(1,1,1,0,0,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		tot=0;
		cnt1=cnt2=cnt3=0;
		ans=0;
		fx=fy=fz=1;
		while(tot<n){
			if(fx) xk=q1.top(),q1.pop();
			if(fy) yk=q2.top(),q2.pop();
			if(fz) zk=q3.top(),q3.pop();
			fx=fy=fz=0;
			while(lx[xk.second]&&!q1.empty()&&cnt1<n/2)xk=q1.top(),q1.pop();
			while(lx[yk.second]&&!q2.empty()&&cnt2<n/2)yk=q2.top(),q2.pop();
			while(lx[zk.second]&&!q3.empty()&&cnt3<n/2)zk=q3.top(),q3.pop();
			if(cnt1==n/2) xk.first=-1;
			if(cnt2==n/2) yk.first=-1;
			if(cnt3==n/2) zk.first=-1;
			if(lx[xk.second]) xk.first=-1;
			if(lx[yk.second]) yk.first=-1;
			if(lx[zk.second]) zk.first=-1;
			maxs=ffx(xk.first,yk.first,zk.first);
			if(maxs==xk.first&&maxs!=yk.first&&maxs!=zk.first){
				cnt1++,ans+=xk.first,lx[xk.second]=1,tot++,fx=1;
			}else if(maxs!=xk.first&&maxs==yk.first&&maxs!=zk.first){
				cnt2++,ans+=yk.first,lx[yk.second]=1,tot++,fy=1;
			}else if(maxs!=xk.first&&maxs!=yk.first&&maxs==zk.first){
				cnt3++,ans+=zk.first,lx[zk.second]=1,tot++,fz=1;
			}
			else if(maxs==xk.first&&maxs==yk.first&&maxs!=zk.first){
				if(cnt1<=cnt2) cnt1++,ans+=xk.first,lx[xk.second]=1,tot++,fx=1;
				else cnt2++,ans+=yk.first,lx[yk.second]=1,tot++,fy=1;
			}
			else if(maxs==xk.first&&maxs!=yk.first&&maxs==zk.first){
				if(cnt1<=cnt3) cnt1++,ans+=xk.first,lx[xk.second]=1,tot++,fx=1;
				else cnt3++,ans+=zk.first,lx[zk.second]=1,tot++,fz=1;
			}
			else if(maxs!=xk.first&&maxs==yk.first&&maxs==zk.first){
				if(cnt2<=cnt3) cnt2++,ans+=yk.first,lx[yk.second]=1,tot++,fy=1;
				else cnt3++,ans+=zk.first,lx[zk.second]=1,tot++,fz=1;
			}
			else if(maxs==xk.first&&maxs==yk.first&&maxs==zk.first){
				if(cnt1<=cnt2&&cnt1<=cnt3) cnt1++,ans+=xk.first,lx[xk.second]=1,tot++,fx=1;
				else if(cnt2<=cnt1&&cnt2<=cnt3) cnt2++,ans+=yk.first,lx[yk.second]=1,tot++,fy=1;
				else if(cnt3<=cnt2&&cnt3<=cnt1) cnt3++,ans+=zk.first,lx[zk.second]=1,tot++,fz=1;
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0; 
} 
/*
 3
 4
 4 2 1
 3 2 4
 5 3 4
 3 5 1
 4
 0 1 0
 0 1 0
 0 2 0
 0 2 0
 2
 10 9 8
 4 0 0
*/
//			if(cnt1<n/2)cnt1++,ans+=xk.first;
//			else if(yk.first>zk.first){
//				if(cnt2<n/2) cnt2++,ans+=yk.first;
//				else if(cnt3<n/2) cnt3++,ans+=zk.first;
//				else break;
//			}else {
//				if(cnt3<n/2) cnt3++,ans+=zk.first;
//				else if(cnt2<n/2) cnt2++,ans+=yk.first;
//				else break;
//			} 
