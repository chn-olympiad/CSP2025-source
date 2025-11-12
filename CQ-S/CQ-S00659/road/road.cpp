#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e4+5;
ll n,m,k,c[N],a[10][N],dad[N],uu[N],vv[N],ww[N],p,ans,cnt,g[1005][1005],d; 
bool vis[N];
struct node
{
	ll v,u,w;
};
struct edge
{
	ll u,w;
};
vector <node> vec[N];
vector <node> vec_1;
vector <ll> aa,bb[N];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
ll gf(ll x)
{
	if(dad[x]==x) return x;
	dad[x]=gf(dad[x]);
	return dad[x];
}
void un(ll x,ll y)
{
	dad[gf(x)]=gf(y);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(!k)
	{
		for(ll i=1;i<N;i++) dad[i]=i;
		for(ll i=1;i<=m;i++)
		{
			ll u,v,w;
			cin>>u>>v>>w;
			vec_1.push_back({u,v,w});
			//vec[u].push_back({v,w});
			//vec[v].push_back({u,w});
		}
		sort(vec_1.begin(),vec_1.end(),cmp);
		
		for(auto j:vec_1)
		{
			ll u=j.u;
			ll v=j.v;
			if(gf(u)!=gf(v))
			{
//				cout<<u<<" "<<v<<"\n"; 
				ans+=j.w;
				un(u,v);
				cnt++;
			}
			if(cnt==m-1) break;	
		}
		cout<<ans;
		return 0; 
	}
	for(ll i=1;i<N;i++) dad[i]=i;
	for(ll i=1;i<=m;i++)
	{
//		ll u,v,w;
		cin>>uu[i]>>vv[i]>>ww[i];
//		vec_1.push_back({uu[i],vv[i],ww[i]});
		vec[uu[i]].push_back({vv[i],ww[i]});
		vec[vv[i]].push_back({uu[i],ww[i]});
	}
	for(ll i=1;i<=k;i++)
	{
		cin>>c[i];//c[i]=0
		for(ll j=1;j<=n;j++) 
		{
			ll tmp=0;
			cin>>tmp;
			if(tmp==0)
			{
//				for(ll i=1;i<=m;i++)
//				{
//					if(uu[i]==j||vv[i]==j) ww[i]=min(tmp,ww[i]);
//				}
				//cout<<j;&&
				
				aa.push_back(j);//存特殊点 
			}
//			cout<<j<<" ";
			bb[i].push_back(tmp);//存边 与i-1号点 
			//bb中 i 对应 i+1
//			vec.push_back({i,j,a[i][j]});
		}
	}
//	for(auto k:bb[1]) cout<<k<<" ";
	for(ll k=0;k<aa.size();k++)//枚举 特殊点 
	{
		int j=aa[k];
		for(ll i=1;i<=m;i++)//枚举边 
		{//与其相连的
			if(uu[i]==j) 
			{
			//	cout<<k<<"&&&&";
				ll tmp=bb[k+1][vv[i]-1];
			
				vis[vv[i]]=1;
				ww[i]=min(tmp,ww[i]);
			}
			else if(vv[i]==j)
			{
			//	cout<<"****";
			//	cout<<k<<"&&&&";
				ll tmp=bb[k+1][uu[i]-1];
				vis[uu[i]]=1;
//				cout<<uu[i]<<" "<<ww[i]<<" ";
				ww[i]=min(tmp,ww[i]);
//				cout<<ww[i]<<"\n";
			}
		}
	}
	for(ll k=0;k<aa.size();k++)//枚举 特殊点
	{
		ll j=aa[k];
		for(ll i=0;i<bb[k+1].size();i++)//枚举边 
		{
//			cout<<"&&&";
			if(!vis[i+1])// 枚举遗漏点 
			{
//				cout<<j<<" "<<i+1<<"\n";
				uu[++d]=j;
				vv[++d]=i+1;
				ww[++d]=min(bb[k+1][i],ww[d]);
//				vec_1.push_back({j,i+1,bb[k+1][i]});
			}
		}
	}
	for(ll i=1;i<=m+d;i++)
	{
//		cout<<uu[i]<<" "<<vv[i]<<" "<<ww[i]<<"\n";
		vec_1.push_back({uu[i],vv[i],ww[i]});
	}
	sort(vec_1.begin(),vec_1.end(),cmp);
//	for(auto j:vec_1) cout<<j.w<<" ";
	for(auto j:vec_1)
	{
		ll u=j.u;
		ll v=j.v;
		if(gf(u)!=gf(v))
		{
//			cout<<u<<" "<<v<<"\n";
			ans+=j.w;
			un(u,v);
			cnt++;
		}
		if(cnt==m-1) break;
	}
	cout<<ans;
	return 0;
}
/*
4 5 0
1 3 3
1 2 2
3 2 6
3 4 5
2 4 4

4 5 2
1 3 3
1 2 2
3 2 6
3 4 5
2 4 4
0 0 2 9 1 
0 1 0 9 9 
*/
