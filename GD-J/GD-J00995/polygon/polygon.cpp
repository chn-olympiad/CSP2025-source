#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],ans,u;
void dfs(int he,int cen,int maxe){
	int m1x=max(maxe,a[cen]);
	if(cen==n){
		if(he>maxe*2){
			ans++;	
		}	
		return;
	}
	dfs(he+a[cen],cen+1,m1x);
	dfs(he,cen+1,maxe);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans%998244353;
	return 0;
} 
