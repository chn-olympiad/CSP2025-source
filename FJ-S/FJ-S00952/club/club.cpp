#include<bits/stdc++.h>
#define N 200005
using namespace std;
const int mod=10000009;
int T,n,m;
bool cmp[N];
int num[5],ans,v[5][N],f[5][N],ff[5][N];
void dfs(int x,int p,int s){
	if(x>3) return ;
	if(p==n){
		ans=max(ans,s);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!cmp[i]&&num[x]+1<=m){
			cmp[i]=1;
			num[x]++;
			dfs(x,p+1,s+v[x][i]);
			dfs(x+1,p+1,s+v[x][i]);
			num[x]--;
			cmp[i]=0;
		}
	}
}
void work(){
	ans=0;
	memset(num,0,sizeof(num));
	memset(cmp,0,sizeof(cmp));
	memset(f,0,sizeof(f));
	cin>>n;
	m=n/2;
	for(int i=1;i<=n;i++){
		cin>>v[1][i]>>v[2][i]>>v[3][i];
	}
	dfs(1,0,0);
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) work();
	return 0;
}
