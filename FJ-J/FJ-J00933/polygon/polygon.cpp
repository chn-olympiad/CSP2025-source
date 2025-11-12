#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,mod=998244353;
int sum=0;
int n,a[N],cnt=0;
void dfs(int x,int y,int mx,int l){
	if(y>n){
		if(x>2*mx&&l>=3){
			sum++;
			sum%=mod;
//			cout<<x<<":"<<mx<<endl;
		}
		return ;
	}
	for(int i=y;i<=n+1;i++){
		dfs(x+a[i],i+1,max(mx,a[i]),l+1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,1,0,0);
	cout<<sum;
	return 0;
}
