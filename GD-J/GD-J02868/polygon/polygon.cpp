#include<iostream>
#include<algorithm>
using namespace std;

typedef long long lld;
const lld mod = 998244353;

lld a[5100],c;
int n;

void dfs(int step,lld s,lld mx){
	if(step > n){
		if(mx == -1){
			return;
		}
		c += s>mx*2;c %= mod;
		return;
	}
	dfs(step+1,s,mx);
	dfs(step+1,s+a[step],max(mx,a[step]));
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	dfs(1,0,-1);
	cout<<c;
	return 0;
}
