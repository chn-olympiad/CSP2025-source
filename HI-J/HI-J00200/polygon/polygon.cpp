#include<bits\stdc++.h>
#define LL long long
using namespace std;
const int N=5e3+5;
const int mod=998244353;
int n,a[N];
long long cnt;
void dfs(int x,int sum,int num,int maxn){
	if(x==n+1){
		if(sum>2*maxn&&num>=3) cnt=(cnt+(LL)1)%mod;
		return ;
	}
	dfs(x+1,sum,num,maxn);
	dfs(x+1,sum+a[x],num+1,a[x]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(1,0,0,0);
	cout<<cnt;
	return 0;
}

