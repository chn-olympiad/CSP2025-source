#include<bits/stdc++.h>
#define pii pair<int,int>
#define X first
#define Y second
#define ll long long
using namespace std;
inline void dd(int &xx){
	xx=0;
	int ff=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	xx*=ff;
}
const int N=1e5+5;
int n,T;
int sum[4],a[N][4],maxn[N][3];
priority_queue<pii> q[4];
void solve(){
	ll ans=0;
	for(int i=1;i<=3;++i){
		while(q[i].size()) q[i].pop();
		sum[i]=0;
	}
	for(int i=1;i<=n;++i){
		maxn[i][0]=maxn[i][1]=0;
		for(int j=1;j<=3;++j){
			if(!maxn[i][0]||a[i][maxn[i][0]]<a[i][j]) maxn[i][1]=maxn[i][0],maxn[i][0]=j;
			else{
				if(!maxn[i][1]||a[i][maxn[i][1]]<a[i][j]) maxn[i][1]=j;
			}
		}
		maxn[i][2]=6-maxn[i][0]-maxn[i][1];
		int x=maxn[i][0],y=maxn[i][1],z=maxn[i][2],p=0;
		if(sum[x]<n/2) p=x;
		else{
			if(a[i][x]==a[i][y]) p=y;
			else{
				if(-q[x].top().X<a[i][x]-a[i][y]){
					--sum[x],ans+=q[x].top().X;
					int yu=q[x].top().Y;
					q[x].pop();
					q[maxn[yu][1]].push({a[i][maxn[yu][2]]-a[i][maxn[yu][1]],yu});
					++sum[maxn[yu][1]];
					p=x;
				}else{
					p=y;
				}
			}
		}
		++sum[p];
		ans+=a[i][p];
		int yu=0;
		if(p==x) yu=a[i][x]-a[i][y];
		else yu=a[i][y]-a[i][z];
		q[p].push({-yu,i});
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	dd(T);
	while(T--){
		dd(n);
		for(int i=1;i<=n;++i){
			dd(a[i][1]),dd(a[i][2]),dd(a[i][3]);
		}
		solve();
	}
}
/*
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
