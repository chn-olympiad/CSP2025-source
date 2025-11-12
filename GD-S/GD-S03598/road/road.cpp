#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll fa[N],n,m,k,a[11][N],c[11];
struct node{
	ll u,v,val;
}le[N*10],now[N*15];
int find(int k){return fa[k]==k?k:fa[k]=find(fa[k]);}
bool cmp(node x,node y){return x.val<y.val;}
void solveA(){
	ll s=0;
	ll h=0,tot=0;
	for(int i=1;i<=n;i++)
		if(fa[i]==i)tot++;
//	cout<<tot<<endl;
	tot=0;
	for(int i=1;i<=k;i++){
		int p=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]==0){
				p=j;break;
			}
		}
		for(int j=p+1;j<=n;j++){
			if(a[i][j]==0){
				int fx=find(p),fy=find(j);
				if(fx!=fy){
//					cout<<i<<" "<<p<<" "<<i<<" "<<j<<endl;
					fa[fx]=fy;
				}
			}
		}
//		cout<<s<<'\n';
	}
	for(int i=1;i<=k;i++){
		int p=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]==0){
				p=j;break;
			}
		}
		for(int j=1;j<=n;j++){
			int fx=find(p),fy=find(j);
			if(fx!=fy){
				now[++h].u=fx;
				now[h].v=fy;
				now[h].val=a[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(fa[i]==i)tot++;
	for(int i=1;i<=m;i++){
		int fx=find(le[i].u);
		int fy=find(le[i].v);
		if(fx!=fy){
			h++;
			now[h].u=fx;
			now[h].v=fy;
			now[h].val=le[i].val;
		}
	}
//	cout<<tot<<" "<<h<<endl;
	sort(now+1,now+h+1,cmp);
	ll ans=0;
	for(int i=1;i<=h;i++){
		int fx=find(now[i].u);
		int fy=find(now[i].v);
		if(fx!=fy){
//			cout<<fx<<" "<<fy<<" "<<now[i].val<<endl;
			ans+=now[i].val;
			fa[fx]=fy;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>le[i].u>>le[i].v>>le[i].val;
	}
	bool v=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];if(c[i]!=0)v=1;
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
//	cout<<a[1][1]<<" "<<a[1][2]<<endl;
	if(!v){
		solveA();
		return 0;
	}
	sort(le+1,le+m+1,cmp);
	ll ans=0;
	for(int i=1;i<=m;i++){
		int fx=find(le[i].u);
		int fy=find(le[i].v);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=le[i].val;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
4 4 2
1 4 6 
2 3 7
4 2 5
4 3 4
0 1 0 2 4
0 0 1 1 1
*/
