#include<bits/stdc++.h>
using namespace std;
int a[5005];
#define MOD 998244353
long long ans;
int n;
void dfs(int in,long long last,long long lm,int l){
	if(l>n){
		return;
	}
	if(l>=3){
		if(last>lm*2){
			ans++;
			ans%=MOD;
		}
	}
	for(int i=in+1;i<n;i++){
		dfs(i,last+a[i],max(lm,(long long)a[i]),l+1);
	}
	return;
}

			
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}   
	dfs(-1,0,0,0);
	ans%=MOD;
	cout<<ans<<endl;
	return 0;
}
