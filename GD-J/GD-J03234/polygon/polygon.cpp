#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
long long n,ans,a[5001],x;
bool b=true;
void dfs(long long sum,long long max,long long last){
	if(sum>2*max){ 
		ans++;
	}
	for(int i=last-1;i>=1;i--){
		dfs(sum+a[i],max,i);
	}
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			b=false;
		}
	}
	if(b){
		for(int i=2;i<=n-1;i++){
			x=(x+i-1)%Mod;
			ans=(ans+x)%Mod;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		dfs(a[i],a[i],i);
	}
	cout<<ans;
	return 0;
}
