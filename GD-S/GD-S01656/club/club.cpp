#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{int x,y,z;};
struct solveb{int a,b;};
inline bool cmp1(edge p,edge q){return p.x>q.x;}
inline bool cmp2(edge p,edge q){return p.y-p.z>q.y-q.z;}
inline bool cmp(int x,int y){return x>y;}
inline bool cmpv(solveb q,solveb p){return q.a-q.b>p.a-p.b;}
inline void swapp(vector<solveb>&a,vector<solveb>&b){vector<solveb>c=a;a=b;b=c;return;}
vector<int>xx,yy,zz;
inline void solveA(int n){
	sort(begin(xx),end(xx),cmp);int ans=0;
	for(int i=0,j=1;j<=n/2;++j,++i)ans+=xx[i];
	return (void)(cout<<ans<<"\n");
}
inline void solveB(int n){
	int ans=0;vector<solveb>p1,p2;p1.clear();p2.clear();
	for(int i=0;i<(int)(xx.size());++i)
		if(xx[i]>=yy[i])p1.push_back((solveb){xx[i],yy[i]});
		else p2.push_back((solveb){xx[i],yy[i]});
	if((int)(p1.size())>n/2||(int)(p2.size())>n/2){
		if(p2.size()>p1.size())swapp(p1,p2);
		sort(p1.begin(),p1.end(),cmpv);
		int p1s=p1.size();
		for(int i=p1s-1;i>=0;--i)
			if(p1s<=n/2)break;
			else p2.push_back(p1[i]),p1.pop_back(),p1s--;
	}
	for(int i=0;i<(int)(p1.size());++i)ans+=p1[i].a;
	for(int i=0;i<(int)(p2.size());++i)ans+=p2[i].b;
	return (void)(cout<<ans<<"\n");
}
int aaans=-1;
inline void dfs(int now,int x,int y,int z,int n,int cx,int cy,int cz){
	if(now==n){aaans=max(aaans,x+y+z);return;}
	if(cx<n/2)dfs(now+1,x+xx[now],y,z,n,cx+1,cy,cz);
	if(cy<n/2)dfs(now+1,x,y+yy[now],z,n,cx,cy+1,cz);
	if(cz<n/2)dfs(now+1,x,y,z+zz[now],n,cx,cy,cz+1);
	return;
}
inline void solvesmall(int n){
	aaans=-1;dfs(0,0,0,0,n,0,0,0);
	return (void)(cout<<aaans<<"\n");
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	for(int T=1,n;T<=t&&cin>>n;++T){
		xx.clear();yy.clear();zz.clear();
		vector<edge>e[4];e[1].clear();e[2].clear();e[3].clear();
		for(int i=1,u,v,w;i<=n&&cin>>u>>v>>w;++i){
			if(u>=v&&u>=w)e[1].push_back((edge){u,v,w});
			else if(v>=w&&v>=u)e[2].push_back((edge){u,v,w});
			else if(w>=v&&w>=u)e[3].push_back((edge){u,v,w});
			xx.push_back(u);yy.push_back(v);zz.push_back(w);
		}
		if(n<=16){solvesmall(n);continue;}
		vector<int>xxx,yyy,zzz;
		xxx.clear(),yyy.clear();zzz.clear();
		xxx=xx,yyy=yy,zzz=zz;
		sort(begin(zzz),end(zzz));sort(begin(yyy),end(yyy));
		if(yyy[(int)yyy.size()-1]==0&&zzz[(int)zzz.size()-1]==0){solveA(n);continue;}
		if(zzz[(int)zzz.size()-1]==0){solveB(n);continue;}
		int l1=e[1].size(),l2=e[2].size(),l3=e[3].size();
		int ans=0;
		if(l1<=n/2&&l2<=n/2&&l3<=n/2){
			for(edge p:e[1])ans+=p.x;
			for(edge p:e[2])ans+=p.y;
			for(edge p:e[3])ans+=p.z;
			cout<<ans<<"\n";continue;
		}
		if(l2>n/2)swap(l1,l2),swap(e[1],e[2]);
		if(l3>n/2)swap(l1,l3),swap(e[1],e[3]);
		if(l3>l2)swap(l2,l3),swap(e[2],e[3]);
		sort(begin(e[1]),end(e[1]),cmp1);
		for(int i=l1-1,j=l1;j>l1/2;--i,--j)e[2].push_back(e[1][i]),e[1].pop_back();
		sort(begin(e[2]),end(e[2]),cmp2);l2=e[2].size();
		for(int i=l2-1;;--i)
			if(e[2][i].y-e[2][i].z>=0)break;
			else e[3].push_back(e[2][i]),e[2].pop_back();
		for(edge p:e[1])ans+=p.x;
		for(edge p:e[2])ans+=p.y;
		for(edge p:e[3])ans+=p.z;
		cout<<ans<<"\n";
	}
	return 0;
} 
