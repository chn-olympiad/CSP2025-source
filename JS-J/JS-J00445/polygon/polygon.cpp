#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5005,mod = 998244353;
int a[N],ans,n;

void dfs(int x,int d,int sum1,int sum2){
	if(x > n) return;
	
	
	if(sum1 > sum2 && d > 2) ans = ans % mod + 1;
	for(int i = x+1;i<=n;i++){
		dfs(i,d+1,sum1+a[i],a[i]*2);
	}
}

int fanc(int x,int y){
	int sum = 1;
	for(int i = x;i<=y;i++) sum=sum*i%mod;
	return sum;
}

signed main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	
	bool f = 0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		f = (a[i]>1);
	}
	if(f){
		sort(a+1,a+1+n);
	
		dfs(0,0,0,0);
	}
	else{
		
		for(int x = 3;x<=n;x++){
			
			ans= (ans % mod + (fanc(n-x+1,n) / fanc(1,x))) % mod ;

		}
		
	}
	
	cout<<ans;
	
	return 0;
}
