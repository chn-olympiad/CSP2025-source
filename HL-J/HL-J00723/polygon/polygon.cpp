#include<bits/stdc++.h>
using namespace std;	
int n,a[5005];
int dfs(int s,int all,int maxx,int dep){
	if(dep>n&&s>=3&&all>2*maxx){
		return 1;
	}
	else if(dep>n&&(s<3||all<=2*maxx)){
		return 0;
	}
	int sum=0;
	int nmaxx=max(maxx,a[dep+1]);
	sum+=dfs(s+1,all+a[dep+1],nmaxx,dep+1);
	sum+=dfs(s,all,maxx,dep+1);
	return sum%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(0,0,0,0)/2;
	return 0;
}
