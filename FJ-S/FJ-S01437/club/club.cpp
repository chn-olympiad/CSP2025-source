#include <bits/stdc++.h>
#define ll long long
#define xcy rp++
using namespace std;
int t,n;
struct node{
	int x,y,z,id;
}p[100005];
ll ans;
struct mem{
	int w,id;
};
int b[100005];
bool operator<(const mem&a,const mem&b){
	return a.w>b.w;
}
bool cmp(node a,node b){
	return a.x==b.x?a.y==b.y?a.z>b.z:a.y>b.y:a.x>b.x;
}
priority_queue<mem>mab,mbc,mca,mba,mcb,mac;
int ab[100005],ba[100005],ac[100005],ca[100005],bc[100005],cb[100005];
void work(){
	memset(ab,0,sizeof(ab));
	memset(ac,0,sizeof(ac));
	memset(ba,0,sizeof(ba));
	memset(bc,0,sizeof(bc));
	memset(ca,0,sizeof(ca));
	memset(cb,0,sizeof(cb));
	ans=0;
	while(!mab.empty())mab.pop();
	while(!mbc.empty())mbc.pop();
	while(!mca.empty())mca.pop();
	while(!mac.empty())mac.pop();
	while(!mba.empty())mba.pop();
	while(!mcb.empty())mcb.pop();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y>>p[i].z;
		p[i].id=i;
	}
	//sort(p+1,p+1+n,cmp);
	int nx=0,ny=0,nz=0;
	for(int i=1;i<=n;i++){
		//cout<<ans<<" ";
		int xx=p[i].x,yy=p[i].y,zz=p[i].z;
		if(xx>=yy&&xx>=zz){
			if(nx==n/2){
				while(!ab[mab.top().id])mab.pop();
				while(!ac[mac.top().id])mac.pop();
				mem ob=mab.top(),oc=mac.top();
				int op=0;
				if(ny<n/2)op=yy;
				if(nz<n/2)op=max(op,zz);
				if(ob.w<=oc.w&&ny<n/2){
					if(p[ob.id].y+xx>p[ob.id].x+op){
						ans-=p[ob.id].x;
						ans+=xx+p[ob.id].y;
						mab.pop();
						//mba.push((mem){p[ob.id].y-p[ob.id].x,ob.id});
						mbc.push((mem){p[ob.id].y-p[ob.id].z,ob.id});
						mab.push((mem){xx-yy,i});
						mac.push((mem){xx-zz,i});
						ab[ob.id]=0;
						ac[ob.id]=0;
						ba[ob.id]=1;
						bc[ob.id]=1;
						ab[i]=1;
						ac[i]=1;
						ny++;
						continue;
					}
				}
				else if(p[oc.id].z+xx>p[oc.id].x+op&&nz<n/2){
						ans-=p[oc.id].x;
						ans+=xx+p[oc.id].z;
						mac.pop();
						//mca.push((mem){p[oc.id].z-p[oc.id].x,oc.id});
						mcb.push((mem){p[oc.id].z-p[oc.id].y,oc.id});
						mab.push((mem){xx-yy,i});
						mac.push((mem){xx-zz,i});
						ab[oc.id]=0;
						ac[oc.id]=0;
						ca[oc.id]=1;
						cb[oc.id]=1;
						ab[i]=1;
						ac[i]=1;
						nz++;
						continue;
					}
				else xx=-1;
			}
			else{
				ans+=xx;
				nx++;
				mab.push((mem){xx-yy,i});
				mac.push((mem){xx-zz,i});
				ab[i]=1;
				ac[i]=1;
				continue;
			}
		}
		if(yy>=zz&&yy>=xx){
			if(ny==n/2){
				while(!ba[mba.top().id])mba.pop();
				while(!bc[mbc.top().id])mbc.pop();
				mem oa=mba.top(),oc=mbc.top();
				int op=0;
				if(nz<n/2)op=max(op,zz);
				if(oa.w<=oc.w&&nx<n/2){
					if(p[oa.id].x+yy>p[oa.id].y+op){
						ans-=p[oa.id].y;
						ans+=yy+p[oa.id].x;
						mba.pop();
						//mab.push((mem){p[oa.id].x-p[oa.id].y,oa.id});
						mac.push((mem){p[oa.id].x-p[oa.id].z,oa.id});
						mba.push((mem){yy-xx,i});
						mbc.push((mem){yy-zz,i});
						ba[oa.id]=0;
						bc[oa.id]=0;
						ab[oa.id]=1;
						ac[oa.id]=1;
						ba[i]=1;
						bc[i]=1;
						nx++;
						continue;
					}
				}
				else if(p[oc.id].z+yy>p[oc.id].y+op&&nz<n/2){
						ans-=p[oc.id].y;
						ans+=yy+p[oc.id].z;
						mbc.pop();
						mca.push((mem){p[oc.id].z-p[oc.id].x,oc.id});
						//mcb.push((mem){p[oc.id].z-p[oc.id].y,oc.id});
						mba.push((mem){yy-xx,i});
						mbc.push((mem){yy-zz,i});
						ba[oc.id]=0;
						bc[oc.id]=0;
						ca[oc.id]=1;
						cb[oc.id]=1;
						ba[i]=1;
						bc[i]=1;
						nz++;
						continue;
					}
				else yy=-1;
			}
			else{
				ans+=yy;
				ny++;
				if(xx!=-1)mba.push((mem){yy-xx,i});
				mbc.push((mem){yy-zz,i});
				ba[i]=1;
				bc[i]=1;
				continue;
			}
		}
		if(zz>=xx&&zz>=yy){
			if(nz==n/2){
				while(!ca[mca.top().id])mca.pop();
				while(!cb[mcb.top().id])mcb.pop();
				mem ob=mcb.top(),oa=mca.top();
				int op=0;
				if(ob.w<=oa.w&&ny<n/2){
					if(p[ob.id].y+zz>p[ob.id].z){
						ans-=p[ob.id].z;
						ans+=zz+p[ob.id].y;
						mcb.pop();
						mba.push((mem){p[ob.id].y-p[ob.id].x,ob.id});
						//mbc.push((mem){p[ob.id].y-p[ob.id].z,ob.id});
						mcb.push((mem){zz-yy,i});
						mca.push((mem){zz-xx,i});
						ca[ob.id]=0;
						cb[ob.id]=0;
						ba[ob.id]=1;
						bc[ob.id]=1;
						ca[i]=1;
						cb[i]=1;
						ny++;
						continue;
					}
				}
				else if(p[oa.id].x+zz>p[oa.id].z&&nx<n/2){
						ans-=p[oa.id].z;
						ans+=zz+p[oa.id].x;
						mca.pop();
						mab.push((mem){p[oa.id].x-p[oa.id].y,oa.id});
						//mac.push((mem){p[oa.id].x-p[oa.id].z,oa.id});
						mca.push((mem){zz-xx,i});
						mcb.push((mem){zz-yy,i});
						ca[oa.id]=0;
						cb[oa.id]=0;
						ab[oa.id]=1;
						ac[oa.id]=1;
						ca[i]=1;
						cb[i]=1;
						nx++;
						continue;
					}
			}
			else{
				ans+=zz;
				nz++;
				if(xx!=-1)mca.push((mem){zz-xx,i});
				if(yy!=-1)mcb.push((mem){zz-yy,i});
				ca[i]=1;
				cb[i]=1;
				continue;
			}
		}
	}
	cout<<ans<<"\n";
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
		work();
	return 0;
}

