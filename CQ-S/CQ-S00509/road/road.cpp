#include<bits/stdc++.h>
using namespace std;
int fa[200005],siz[100005];
int find(int x){if(fa[x]==x) return x;return fa[x]=find(fa[x]);}
struct f{int x,y,k;}a[1000005],b[15][10004];
bool cmp(f x,f y){return x.k<y.k;}
vector<f>s[1025],pl;
int c[105];
long long dp[1025];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,ks;cin>>n>>m>>ks;
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){cin>>a[i].x>>a[i].y>>a[i].k;}
	sort(a+1,a+1+m,cmp);long long ans=0;
	for(int i=1;i<=m;i++){
		int u=find(a[i].x),v=find(a[i].y);
		if(u!=v){
			ans=(long long)ans+(long long)a[i].k;
			s[0].push_back(f{a[i].x,a[i].y,a[i].k});
			if(siz[u]>siz[v])siz[u]+=siz[v],fa[v]=u;
			else fa[u]=v,siz[v]+=siz[u];
		}
	}
	for(int i=1;i<=ks;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){cin>>a[j].k;a[j].x=n+i,a[j].y=j;}
		sort(a+1,a+1+n,cmp);
		for(int j=1;j<=n;j++) b[i][j]=a[j];
	}dp[0]=ans;
	for(int i=1;i<(1<<ks);i++) dp[i]=1e18;
	for(int i=0;i<(1<<ks);i++){
		long long xsf=0;
		for(int j=0;j<ks;j++){
			if(!(i&(1<<j))){
				int l=0,ls=1;pl.clear();long long sum=0;
				for(int k=1;k<=n+ks;k++){fa[k]=k;siz[k]=1;}
				while(l<s[i].size()&&ls<=n){
					int u,v,k;
					if(l==s[i].size()){
						u=b[j+1][ls].x,v=b[j+1][ls].y;k=b[j+1][ls].k; ls++;
					}
					else if(ls>n){u=s[i][l].x,v=s[i][l].y,k=s[i][l].k;l++;}
					else{
						if(b[j+1][ls].k<=s[i][l].k){
							u=b[j+1][ls].x,v=b[j+1][ls].y;k=b[j+1][ls].k; ls++;	
						}
						else{u=s[i][l].x,v=s[i][l].y,k=s[i][l].k;l++;}
					}
					int us=find(u),vs=find(v);
					if(us==vs) continue;
					sum=(long long)sum+(long long)k;
					pl.push_back(f{u,v,k});
					if(siz[us]>siz[vs])siz[us]+=siz[vs],fa[vs]=us;
					else fa[us]=vs,siz[vs]+=siz[us];
				}
				if(dp[(i|(1<<j))]>sum){
					dp[(i|(1<<j))]=sum;
					s[(i|(1<<j))].clear();
					for(int k=0;k<pl.size();k++){
						s[(i|(1<<j))].push_back(pl[k]);
					}
				}
			}else xsf+=c[j+1];
		}
		s[i].clear();ans=min(ans,(long long)dp[i]+(long long)xsf);
	}
	cout<<ans;
	return 0;
}
/*
拼尽全力只有80……
完蛋了…… 
想办法把并查集给ban了，看能不能直接vector存
空间爆炸了！！ 
时间也爆炸了！！
不如并查集 ，并查集极限数据给我跑了1.3s
只能期待数据全部都很水了……
*/
