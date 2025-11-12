#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;//a[i]<=2e4
int n,T,cnt,vis[N],vis1[N];
int xx[N],yy[N],zz[N];
int qqq[N];
struct re{
	int x,id,k;
}v[N],G[N];
bool cmp(re x,re y){
	return x.x>y.x;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)vis[i]=0;
	cnt=0;
	int x=0,y=0,z=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>z;
		v[++cnt].x=x;v[cnt].id=1;v[cnt].k=i;
		v[++cnt].x=y;v[cnt].id=2;v[cnt].k=i;
		v[++cnt].x=z;v[cnt].id=3;v[cnt].k=i;
	}
	sort(v+1,v+1+n*3,cmp);
	x=0,y=0,z=0;
	for(int i=1;i<=n*3;i++){
		if(vis[v[i].k]!=0){
			if(vis[v[i].k]==1){
				xx[++x]=i;
			}else if(vis[v[i].k]==2){
				yy[++y]=i;
			}else zz[++z]=i;
			continue;
		}
		vis[v[i].k]=v[i].id;
		qqq[v[i].k]=i;
		sum+=v[i].x;
	}
	if(x>n||y>n||z>n){
		int qq=0;
		if(x>n){
			qq=x;int ans=0; 
			for(int i:xx){
				G[i].k=v[i].k,G[i].x=v[v[i].k].x;
				ans+=v[qqq[v[i].k]].x;
			}
			sum-=ans/2;
		}else if(y>n){
			qq=y;int ans=0; 
			for(int i:yy){
				G[i].k=v[i].k,G[i].x=v[v[i].k].x;
				ans+=v[qqq[v[i].k]].x;
			}
			sum-=ans/2;
		}else{
			qq=y;int ans=0; 
			for(int i:yy){
				G[i].k=v[i].k,G[i].x=v[v[i].k].x;
				ans+=v[qqq[v[i].k]].x;
			}
			sum-=ans/2;
		}
		sort(G+1,G+1+qq,cmp);
		
		for(int i=1;i<=n;i++)vis1[i]=0;
		int cc=0;
		for(int i=1;i<=qq;i++){
			if(vis1[G[i].k]!=0||cc==qq-n){
				if(vis[G[i].k]==2)sum+=v[qqq[G[i].k]].x;
				continue;
			}
			cc++;
			vis1[G[i].k]++;
			sum+=G[i].x;
		}
	}
	cout<<sum<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		solve();
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
/*
18 
4 
13
*/
