#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
奶龙：我最爱的球星是克里斯蒂亚诺罗纳尔多，2026年世界杯葡萄牙将夺得大力神杯
*/
const int N=505,mod=998244353;
int c[N],n,m,ans;
char a[N];
bool v[N];
void dfs(int x,int y){
	if(x>n){
		if(n-y>=m){
			ans=(ans+1)%mod;
		}
		return ;
	}
	if(n-y<m){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		int h=0;
		if(a[x]=='0'||y>=c[i]){
			h=1;
		}
		dfs(x+1,y+h);
		v[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans<<"\n";
	return 0;
}
