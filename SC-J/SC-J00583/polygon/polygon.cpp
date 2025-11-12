#include<bits/stdc++.h>
using namespace std;
int n=0;
int arr[10000];
long long dp[10000];
int ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	sort(arr+1,arr+n+1);
	if(n==3)
	{
		if(arr[3]*2>=arr[1]+arr[2])cout<<1;
		else cout<<0;
	}
	return 0;
}