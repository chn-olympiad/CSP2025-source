#include<bits/stdc++.h>
using namespace std; 
int n,sum,a[5010],b[5010];
void dfs(int d,int s,int m,int k){
	if(d>=3&&s>m*2)sum=(sum+1)%998244353;
	if(d==n)return;
	for(int i=k+1;i<=n;i++){
		if(!b[i]){
			b[i]++;
			dfs(d+1,s+a[i],max(m,a[i]),i);
			b[i]--;
		}
	}
	return;
}
int main(){
  	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0,0);
	cout<<sum;
  	return 0;
}
