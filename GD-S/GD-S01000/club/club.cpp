#include<bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int N=1e3+5,INF=0x7f7f7f7f;
struct person{
	int a,b,c;
	bool operator<(const person& p2)const{
		return a>p2.a;
	}
}p[N];
int t,n,dp[2][N][N];
void solve60pts(){
	int h=n>>1,maxn=0;
	memset(dp,0,sizeof(int)*(n*n+5));
	for(int i=1;i<=n;i++){
		bool b=i&1;
		for(int x=0;x<=min(i,h);x++){
			for(int y=max(i-min(i,h)-x,0);y<=min(i-x,h);y++){
				int z=i-x-y;
				dp[b][x][y]=max({
					x>0?dp[!b][x-1][y]+p[i].a:-INF,
					y>0?dp[!b][x][y-1]+p[i].b:-INF,
					z>0?dp[!b][x][y] + p[i].c:-INF
				});
				if(i==n)maxn=max(maxn,dp[b][x][y]);
			}
		}
	}
	cout<<maxn<<'\n';
	return;
}
void solveA5pts(){
	sort(p+1,p+n+1);
	int sum=0;
	for(int i=1;i<=n/2;i++)sum+=p[i].a;
	cout<<sum<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n;
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(p[i].c!=0||p[i].b!=0)flag=false;
		}
		if(!flag)solve60pts();
		else solveA5pts();
	}
	return 0;
}
/*
note:
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

