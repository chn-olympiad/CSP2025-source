#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,k,res=1e9+10;
bool op=0;
struct node{
	int l,r,w;
	int pd;
}a[2000005];
int root[2005];
int qwq[15];
int t[15];
bool cmp(node a,node b){
	return a.w+a.pd<b.w+b.pd;
}
int find(int x){
	if(root[x]!=x)return find(root[x]);
	else return x;
}
int kruskal(int n,int m){
	for(int i=1;i<=n;i++){
		root[i]=i;
	}
	
	sort(a+1,a+m+1,cmp);
	int pos=0,ans=0;
	for(int i=1;i<=m;i++){
		if(find(a[i].l)==find(a[i].r)){
			continue;
		}
		else {
			if(!qwq[a[i].pd]){
				qwq[a[i].pd]=1;
				ans+=t[a[i].pd];
			}
			root[a[i].l]=root[a[i].r];
			ans+=a[i].w;
			pos++;
		}
		if(pos==n-1)break;
	}
	if(pos!=n-1)op=1;
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].l>>a[i].r>>a[i].w;
	}
	if(!op)res=kruskal(n,m);
	int nown=n,nowm=m;
	for(int i=1;i<=k;i++){
		cin>>t[i];
		nown++;
		for(int j=1;j<=n;j++){
			int w;cin>>w;
			a[++nowm]=(node){nown,j,w,i};
		}
		memset(qwq,0,sizeof(qwq));
		res=min(res,kruskal(nown,nowm));
	}
	cout<<res<<endl;
	return 0;
}
