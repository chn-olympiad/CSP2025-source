#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long minl=LLONG_MAX;
int dp[1<<10+10];
int fa[10005];
struct dd{
	int u,x,w,f=0;
}a[1100005],b[1000005];
int f[15][10005];
int ac[15];
inline bool cmp(dd x,dd y){
	return x.w<y.w;
}
inline int findfa(int x){
	if(fa[x]!=x)fa[x]=findfa(fa[x]);
	return fa[x];
}
inline bool check(){
	int x=findfa(1);
	for(int i=1;i<=n;i++){
		if(x!=findfa(i))return false;
	}
	return true;
}
long long sum=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>b[i].u>>b[i].x>>b[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>ac[i];
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
		}
	}
	for(int xx=0;xx<=(1<<k)-1;xx++){
		int len=0;sum=0;
		memset(a,0,sizeof a);
		for(int c=0,kk=xx;c<k;c++){
			if(kk&(1<<c)){
				for(int o=1;o<=n;o++){
					a[++len].u=c+n+1;
					a[len].x=o;
					a[len].w=f[c+1][o];
				}
				sum=sum+ac[c+1];
			}
			
		}
		for(int i=1;i<=m;i++){
			a[++len]=b[i];
		}
		for(int i=1;i<=n+k;i++)fa[i]=i;
		sort(a+1,a+1+len,cmp);
		for(int i=1;i<=len;i++){
			int x=findfa(a[i].u),y=findfa(a[i].x);
			if(x==y)continue;
			else {
				fa[x]=fa[y];
				sum+=a[i].w;
			}
			if(check())break;
		}
		minl=min(minl,sum);
	}
	cout<<minl;
		
		
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
