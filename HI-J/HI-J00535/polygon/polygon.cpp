#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
int a[5000];
ll ans=0;
void dfs(int j,int h,int ma,int cd){
	if(h>2*ma){
		ans++;
	}
	if(j==0)return ;
	for(int i=j-1;i>=(cd<3)*(2-cd);i--){
		dfs(i,h+a[i],max(ma,a[i]),cd+1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i>1)dfs(i,a[i],a[i],1);
	}
	cout<<ans%998244353;
	return 0;
} 
