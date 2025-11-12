#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[5002];
int n;
ll ans = 0;
void dfs(int num,int maxn,int sum,int index){
	if(sum+a[index]>2*max(maxn,a[index])&&num+1>=3){
		ans++;
	}
	if(index == n)return;
	dfs(num,maxn,sum,index+1);
	dfs(num+1,max(a[index],maxn),sum+a[index],index+1);
}


int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	
	int maxn = -1;
	ll sum = 0; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn)maxn = a[i];
		sum += a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if (sum<=2*maxn){
		cout<<0;
		return 0;
	}
	else if(n==3){
		cout<<1;
		return 0;
	}
	dfs(0,0,0,1);
	cout<<ans%998244353;
	return 0;
}