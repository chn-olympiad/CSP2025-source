//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
constexpr const int N=5000,V=5000,P=998244353;
int n,ans,a[N+1],dp[N*V+1];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dp[0]=1;
	for(int i=1,sum=0;i<=n;i++){
		for(int j=a[i]+1;j<=sum;j++){
			ans=(ans+dp[j])%P;
		}
		sum+=a[i];
		for(int j=sum;a[i]<=j;j--){
			dp[j]=(dp[j]+dp[j-a[i]])%P;
		}
	}
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

