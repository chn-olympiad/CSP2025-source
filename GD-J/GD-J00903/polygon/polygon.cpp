#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],k;
void dfs(long long sum,long long x,long long y){
	if(x==y){
		if(sum+a[y]>a[y]*2)k++,k%=998244353;
	}
	else{
		dfs(sum+a[x],x+1,y);
		dfs(sum,x+1,y);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
	    dfs(0,1,i);
	}	
	cout<<k%998244353;
	return 0;
}
