#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int N=998244353;
int n,a[5005],ans,b;
void dfs(int x,int num,int m,int sum){
    if(sum>=3&&num>2*m&&num>b){
    	ans=(ans+1)%N;
	}
	if(x>n){
		return ;
	}
    b=num;
	dfs(x+1,num+a[x],max(m,a[x]),sum+1);
	dfs(x+1,num,m,sum);
}
int main(){
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
