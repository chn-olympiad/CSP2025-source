#include<bits/stdc++.h>
using namespace std;
int a[5005],n,sum;
void dfs(int x,int c,int ans,int maxn){
	if(c>=3){
		if(ans>maxn*2){
			sum++;
		}
	}
	for(int i=x+1;i<n;i++){
		dfs(i,c+1,ans+a[i],max(maxn,a[i]));
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)dfs(i,1,a[i],i);
	cout<<sum;
}
