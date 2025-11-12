#include<bits/stdc++.h>
using namespace std;
int n,a[5010],pr[5010],p,sum;
bool f[5010];
void dfs(int x,int d,int maxn){
	if(d==p+1){
		if(x>maxn*2){
			sum++;
		}
		return;
	}
	if(d==p){
		dfs(x+a[d],d+1,max(maxn,a[d]));
	}else{
		dfs(x+a[d],d+1,max(maxn,a[d]));
		dfs(x,d+1,maxn);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		p=i;
		dfs(0,1,0);
	}
	cout<<sum;
	return 0;
}
