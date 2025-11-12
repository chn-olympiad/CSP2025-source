#include<bits/stdc++.h>
using namespace std;
int n,q[5010];
long long sum;
bool te = 1;//特殊性质： 
void dfs(int summ,int maxx,int i,int x){//x用了几只小木棍
	if(x>=3&&summ>maxx*2){
		sum++;
		sum%=998244353;
	}
	x++;
	for(int j = i+1;j<=n;j++){
		dfs(summ+q[j],max(maxx,q[j]),j,x);
	}
	return ;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>q[i];
		if(q[i]!=1){
			te = 0;
		}
	}
	if(te){
		cout<<n*(n+1)/2;
		return 0;
	}
	for(int i = 1;i<=n-2;i++){
		dfs(q[i],q[i],i,1);
	}
	cout<<sum;
	return 0;
}
