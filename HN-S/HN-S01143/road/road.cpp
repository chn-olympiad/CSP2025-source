#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e4+5,M=2e6+5;
int f[N],n,cnt,x[M],y[M],w[M],id[M],b[M];
int ans=1e18;
int m,k,c[N],val,tot=0;
inline int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
inline bool cmp(int x,int y){
	return w[x]<w[y];
}
inline int LeastTree(int nw,int val){
	int sum=val;
	for(int i=1;i<=n;i++)
		f[i]=i;
	cnt=nw;
	for(int i=1;cnt!=1;i++){
		if(sum>ans) return sum;
		int l=find(x[id[i]]);
		int r=find(y[id[i]]);
		int val=w[id[i]];
		if(l==0||r==0) continue; 
		if(l==r) continue;
		f[l]=r;
		sum+=w[id[i]];
		cnt--;
	}
	return sum;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x[i]>>y[i]>>w[i];
	}
	for(int j=1;j<=m;j++)
		id[++tot]=j;
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>val;
			x[m+i*n+j]=i+1+n;
			y[i*n+j+m]=j;
			w[i*n+j+m]=val;
			id[++tot]=i*n+j+m;
		}
	}
	
	sort(id+1,id+1+tot,cmp);
	
	for(int i=0;i<(1<<k);i++){
		int tot=0,cnt=0,num=n;
		
		for(int j=0;j<k;j++)
			if((i>>j)&1){
				cnt+=c[j];
				num++;
				f[j+n+1]=j+n+1;
			}
			else f[j+n+1]=0;

		ans=min(ans,LeastTree(num,cnt));
	}
	cout<<ans;
	return 0;
}
/*
505585650
120687843014
*/

