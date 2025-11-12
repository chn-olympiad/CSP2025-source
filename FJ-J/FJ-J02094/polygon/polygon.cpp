#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005];
long long int cnt;

void dfs(int i,int sum,int maxn){
	if(i>n){
		if(sum>maxn*2){
			cnt++;
			cnt%=mod;
		}
		return;
	}
	if(sum>maxn*2){
		long long int m=pow(2,n-i+1);
		m=(m+cnt)%mod;
		cnt=m;
		return ;
	}
	dfs(i+1,sum,maxn);
	if(maxn==0){
		maxn=a[i];
	}
	dfs(i+1,sum+a[i],maxn);
	return;
}

bool cmp(int x,int y){
	return x>=y;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dfs(1,0,0);
	cout<<cnt;
	return 0;
} 
