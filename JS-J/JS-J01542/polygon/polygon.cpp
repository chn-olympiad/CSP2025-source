#include <bits/stdc++.h>
using namespace std;
int m,a[10005],b[10005];
long long sum=0;
bool v[10005];
int j;
void dfs(int p,long long sum1){
	if(p==j+1){
		int maxn=-1;
		for(int i=1;i<=j;i++){
			maxn=max(maxn,a[b[i]]);
		}
		if(sum1>maxn*2){
			sum++;
		}
		sum%=998244353;
		return;
	}
	for(int i=b[p-1]+1;i<=m;i++){
		if(!v[i]){
			v[i]=1;
			b[p]=i;
			dfs(p+1,sum1+a[i]);
			v[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
    for(j=3;j<=m;j++){
		dfs(1,0);
	}
	cout<<sum;
    return 0;
}
