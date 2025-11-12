#include<bits/stdc++.h>
#define ll long  long
using namespace std;
const int N=5e4+10,mod=998244353;
int n;
int a[N];
ll ans;
int flag;
int b[N][21];
void dfs(int x,int now,int num,int maxx){
	if(x>n&&now>=3){
		if(maxx*2<num) ans++;
		ans%=mod;
		return;
	}
	if(x>n) return;
	dfs(x+1,now,num,maxx);
	dfs(x+1,now+1,num+a[x],max(maxx,a[x]));
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
}

/*
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1



*/
