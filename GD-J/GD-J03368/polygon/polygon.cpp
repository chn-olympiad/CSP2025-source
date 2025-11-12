#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5050];
void dfs(int zd,int sum,int num,int cs){
	num++;
	if(num>n){
		if(sum>2*zd&&cs>=3){
			ans++;
			ans%=998244353;
		}
		return;
	}
	dfs(a[num],sum+a[num],num,cs+1);
	dfs(zd,sum,num,cs);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		cout<<1;
		return 0;
	}
	else if(n<=29){
		dfs(0,0,0,0);
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
			ans*=2;
			ans%=998244353;
		}
		ans-=n*n;
		if(ans<0){
			ans+=998244353;
		}
		cout<<ans;
	}
	return 0;
}
