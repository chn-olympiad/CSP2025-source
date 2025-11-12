#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 50005
using namespace std;
typedef long long ll;
int a[MAXN][3];
int v1[MAXM],v2[MAXM],v3[MAXM];
int ans,n;
int sum(int _1,int _2,int _3)
{
	int tot=0;
	for(int i=1;i<=_1;++i) tot+=a[v1[i]][0];
	for(int i=1;i<=_2;++i) tot+=a[v2[i]][1];
	for(int i=1;i<=_3;++i) tot+=a[v3[i]][2];
	return tot;
}
void dfs(int x,int _1,int _2,int _3)
{
	if(x>n){
		ans=max(ans,sum(_1,_2,_3));
		return;
	}
	if(_1<n/2){
		v1[_1+1]=x;
		dfs(x+1,_1+1,_2,_3);
	}
	if(_2<n/2){
		v2[_2+1]=x;
		dfs(x+1,_1,_2+1,_3);
	}
	if(_3<n/2){
		v3[_3+1]=x;
		dfs(x+1,_1,_2,_3+1);
	} 
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i) cin>>a[i][0]>>a[i][1]>>a[i][2];
		dfs(1,0,0,0);
		cout<<ans<<'\n';
		ans=0;
	}
	return 0;
}

