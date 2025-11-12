#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=2e6+5;
int n,m,k,c[15],a[15][N],f[N];
long long ans;
struct node{
	int u,v,w;
}s[M];
bool cmp(node a,node b){
	return a.w<b.w;
}
int get(int x){
	if (f[x]!=x)return f[x]=get(f[x]);
	return f[x];
}
void solve(int x){
	for (int i=0;i<=n;i++)f[i]=i;
	int sum=n+1;
	for (int i=m+1;i<=m+n;i++){
		s[i].w=a[x][i-m];
	}
	sort(s+1,s+m+n+1,cmp);
	for (int i=1;i<=m+n;i++){
		if (get(s[i].u)!=get(s[i].v)){//?
			f[get(s[i].u)]=get(s[i].v);//?
			ans+=s[i].w;
			if (--sum==1)break;
		}
	}
	return ;
}
void solve1(){
	for (int i=1;i<=n;i++)f[i]=i;
	int sum=n;
	sort(s+1,s+m+1,cmp);
	for (int i=1;i<=m;i++){
		if (get(s[i].u)!=get(s[i].v)){//?
			f[get(s[i].u)]=get(s[i].v);//?
			ans+=s[i].w;
			if (--sum==1)break;
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
	}
	for (int i=m+1;i<=m+n;i++){
		s[i].u=0,s[i].v=i-m;
	}
	for (int i=1;i<=k;i++){
		cin>>c[i];
		for (int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	long long mn=1e18;
	solve1();
//	cout<<ans<<' ';
	mn=min(mn,ans);
	for (int i=1;i<=k;i++){
		ans=c[i];
		solve(i);
//		cout<<ans<<' ';
		mn=min(mn,ans);
	}
	cout<<mn;
	return 0;
}
