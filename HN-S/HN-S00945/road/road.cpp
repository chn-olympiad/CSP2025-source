#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,d;
}a[1000005],b[1000005];
int n,m,k,len,f[10015],c[15][10015];
bool tg[15];
long long ans;
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void dfs(int x){
	if(x==k+1){
		vector<node> p;
		long long res=0;
		for(int i=1;i<=n+k;i++)
			f[i]=i;
		for(int i=1;i<=len;i++)
			p.push_back(b[i]);
		for(int i=1;i<=k;i++){
			if(!tg[i]) continue;
			res+=c[i][0];
			for(int j=1;j<=n;j++)
				p.push_back({n+i,j,c[i][j]});
		}
		sort(p.begin(),p.end(),[](node x,node y){return x.d<y.d;});
		for(node v:p){
			int x=find(v.x),y=find(v.y);
			if(x!=y){
				f[x]=y;
				res+=v.d;
			}
		}
		ans=min(ans,res);
		return;
	}
	tg[x]=0;
	dfs(x+1);
	tg[x]=1;
	dfs(x+1);
	tg[x]=0;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	int st=clock();
	ans=LONG_LONG_MAX;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		cin>>a[i].x>>a[i].y>>a[i].d;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	sort(a+1,a+1+m,[](node x,node y){return x.d<y.d;});
	for(int x,y,j,i=1;i<=m;i++){
		j=i;
		while(a[j].d==a[i].d) j++;
		for(int ii=i;ii<j;ii++){
			x=find(a[ii].x),y=find(a[ii].y);
			if(x!=y)
				b[++len]=a[ii];
		}
		for(int ii=i;ii<j;ii++){
			x=find(a[ii].x),y=find(a[ii].y);
			if(x!=y)
				f[x]=y;
		}
		i=j-1;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
/*
15:12 start
zuixiaoshengchengshu?
i forget english qwq
wtf k<=10????????
O(mlogm+2^k*n)
wo kan cuo ti mu le
******
15;47 注意到我什么也每注意到
afo了...
17:27 AC?
who knows
IM**********
*/