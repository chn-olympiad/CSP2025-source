#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int flag=1;
int sum[5005];
long long ans=0;
void dfs(int i,int sum,int x,int id){
	if(i==x){
		for(int j=n;j>=id+1;j--){
			if(sum>a[j]){
				ans+=j-id;
				return ;
			}
		}
	}
	if(n-id<x-i){
		return ;
	}
	for(int j=id+1;j<=n;j++){
		dfs(i+1,sum+a[j],x,j);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag=0;
		}
	}
	sort(a+1,a+1+n);
	if(flag==1){
		for(int i=3;i<=n;i++){
			int x=1,y=1;
			for(int j=n;j>=n-i+1;j--){
				x*=j;
			}
			for(int j=1;j<=i;j++){
				y*=j;
			}
			ans+=x/y;
		}
		cout<<ans;
	}
	else{
		for(int i=3;i<=n;i++){
			dfs(1,0,i,0);
		}
		cout<<ans;
	}
	return 0;
}/*
5
2 2 3 8 10
5
1 2 3 4 5
20
2 3 5 8 4 2 9 4 3 6 2 3 5 8 4 2 9 4 3 6
* 64pts
*/
