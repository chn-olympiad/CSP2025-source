#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int t,n,d;
struct node{
	int x,y,z;
	int mmx(){
		return max(x,max(y,z));
	}
}a[N];
ll ans;
ll mx[N],my[N],mz[N];
ll nx,ny,nz;
void dfs(int xx,int yy,int zz,int s,ll sum){
	if(s>n){
		ans=max(ans,sum);
		return ;
	}
	if(xx<d) dfs(xx+1,yy,zz,s+1,sum+a[s].x);
	if(yy<d) dfs(xx,yy+1,zz,s+1,sum+a[s].y);
	if(zz<d) dfs(xx,yy,zz+1,s+1,sum+a[s].z);
	return ;
}
void fp(int i){
	if(a[i].mmx()==a[i].x) mx[++nx]=i;
	else if(a[i].mmx()==a[i].y) my[++ny]=i;
	else if(a[i].mmx()==a[i].z) mz[++nz]=i;
	return ;
}
bool cmp1(ll xx,ll yy){
	if(a[xx].x==a[yy].x) return a[xx].y<a[yy].y;
	return a[xx].x>a[yy].x;
}
bool cmp2(ll xx,ll yy){
	if(a[xx].y==a[yy].y) return a[xx].x<a[yy].x;
	return a[xx].y>a[yy].y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		d=n/2,ans=0;
		for(int i=1;i<=n;++i){
			cin>>a[i].x>>a[i].y>>a[i].z;
			fp(i);
		}
		if(n<=30)
			dfs(0,0,0,1,0);
		else{
			sort(mx+1,mx+nx+1,cmp1);
			sort(my+1,my+ny+1,cmp2);
			if(nx>d)
				for(int i=d+1;i<=nx;++i)
					my[++ny]=mx[i];
			if(ny>d)
				for(int i=d+1;i<=ny;++i)
					mx[++nx]=my[i];
			for(int i=1;i<=d;++i){
				ans+=a[mx[i]].x;
			} 
			for(int i=1;i<=d;++i){
				ans+=a[my[i]].y;	
			} 
		}	
		cout<<ans<<endl;
	}
	return 0;
}
