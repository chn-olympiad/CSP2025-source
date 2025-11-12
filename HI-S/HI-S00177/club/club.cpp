#include<bits/stdc++.h>
using namespace std;
struct node{
	int f1,f2,f3;
}a[100100];
int cmp(node s1,node s2){
	return s1.f1+s1.f2+s1.f3>s2.f1+s2.f2+s2.f3;
}
int dp[100100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;int sum=0;
		int fn1=0,fn2=0,fn3=0;
		for(int i=1;i<=n;i++) cin>>a[i].f1>>a[i].f2>>a[i].f3;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(fn1+1<=n/2&&fn2+1<=n/2&&fn3+1<=n/2){
				dp[i]=max(dp[i-1]+a[i].f1,max(dp[i-1]+a[i].f2,dp[i-1]+a[i].f3));
				if(a[i].f1>a[i].f2&&a[i].f1>a[i].f3) fn1++;
				else if(a[i].f2>a[i].f1&&a[i].f2>a[i].f3) fn2++;
				else if(a[i].f3>a[i].f1&&a[i].f3>a[i].f2) fn3++;
			}
			else if(fn1+1>n/2&&fn2+1<=n/2&&fn3+1<=n/2){
				dp[i]=max(dp[i-1]+a[i].f2,dp[i-1]+a[i].f3);
				if(a[i].f2>a[i].f3) fn2++;
				else fn3++;
			}
			else if(fn2+1>n/2&&fn1+1<=n/2&&fn3+1<=n/2){
				dp[i]=max(dp[i-1]+a[i].f1,dp[i-1]+a[i].f3);
				if(a[i].f1>a[i].f3) fn1++;
				else fn3++;
			}
				
			else if(fn3+1>n/2&&fn2+1<=n/2&&fn1+1<=n/2){
				dp[i]=max(dp[i-1]+a[i].f2,dp[i-1]+a[i].f1);
				if(a[i].f1>a[i].f2) fn1++;
				else fn2++;
			}
		}
		cout<<dp[n]<<endl;
	}
	
 return 0;
}

