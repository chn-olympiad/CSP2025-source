#include<bits/stdc++.h>
using namespace std;
int n,a[5005],d[5005],cnt,sum,maxn,o;
void dfs(int x){
	d[++cnt]=a[x];
	if(cnt>=3){
		for(int i=1;i<=cnt;i++){
			sum+=d[i];
			maxn=max(maxn,d[i]);
		}
		if(sum>2*maxn){
			o++;
			o%=998244353;
		}
		sum=0,maxn=0;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i);
	}
	cnt--;
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		maxn=0;
		sum=0;
		cnt=0;
		dfs(i);
	}
	cout<<o%998244353;
	return 0;
}
