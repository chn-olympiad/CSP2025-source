#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,x,num;
long long k,sum;
int a[N],dp[N];
map<long long,int>m;

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	m[0]=-1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num;
		sum^=num;
		x=m[sum^k];
		if(x>0)a[i]=x;
		else if(x==-1)a[i]=0;
		else a[i]=-1;
		m[sum]=i;
	}
	
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		if(a[i]>=0)dp[i]=max(dp[i],dp[a[i]]+1);
	}
	
	cout<<dp[n];
	return 0;
}
