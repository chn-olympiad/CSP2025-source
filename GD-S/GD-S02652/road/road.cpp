#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e4+10; 
struct node{
	int l,r;
	ll val;
}a[N*39200];
bool cmp(node x,node y){
	if(x.val==y.val){
		if(x.l==y.l)return x.r<y.r;
		return x.l<y.l;
	}
	return x.val<y.val;
}
int n,m,k,fa[N];
int w[N];
ll ans=0;
int find(int x){
	if(fa[x]==x)return x;
	return x=fa[x]=find(fa[x]);
}
bool vis[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].l>>a[i].r>>a[i].val;
	}
	for(int i=1;i<=k;i++){
		int v=0;
		cin>>v;
		for(int j=1;j<=n;j++)cin>>w[j];
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				m++;
				a[m].l=j;
				a[m].r=k;
				a[m].val=1ll*w[j]+1ll*w[k]+1ll*v;
			}
		}
	}
	sort(a+1,a+1+m,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int fx=find(a[i].l),fy=find(a[i].r);
		if(fx==fy)continue;
		fa[fx]=fy;
		ans+=a[i].val;
		if(!vis[a[i].l]){
			vis[a[i].l]=1;
			cnt++;
		}
		if(!vis[a[i].r]){
			vis[a[i].r]=1;
			cnt++;
		}
		if(cnt==n)break;
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
