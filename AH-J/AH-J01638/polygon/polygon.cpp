#include<bits/stdc++.h>
using namespace std;
int n;
int a[50005];
int ans,cnt,maxn,shu;
int f[50005];
int dfs(int x){
	if(x>=n-2&&cnt>maxn*2&&shu>=3){
		return 1;
	}
	shu++;
	cnt+=x;
	if(x>maxn){
		maxn=x;
	}
	int take=dfs(x+1);
	int no=dfs(x+2);
	ans=take+no; 
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<dfs(0);
	return 0;
}
