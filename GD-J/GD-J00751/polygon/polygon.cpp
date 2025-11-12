#include<iostream>
#include<bitset>
#include<string>
#include<cstdio>
using namespace std;
using ll=long long;
const ll MAXN=5010,MOD=998244353;
bitset<MOD+5>ds;
ll a[MAXN],ans,n;
void dfs(int X,int K,int L,ll S,ll MAX){//要选的第 X 个数，,已经选了 K 个数，要选 L 个数，和是 S ,最大值 
	if(K-1==L){
		if(S>MAX*2&&ds[S]==false){
			ds[S]=true;
			//cout<<S<<" "<<MAX<<" "<<L<<endl;
			ans++;
			return;
		}
		return;
	}
	for(int i=X;i<=n;i++){
		dfs(i+1,K+1,L,(S+a[i]),max(MAX,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){
		for(int l=3;x+l<=n;l++){
			dfs(x,0,l,0,a[x]);
		}
	}
	cout<<(ans+3)%MOD;
}
/*
5
2 2 3 8 10
*/ 
/*
5
1 2 3 4 5
*/
