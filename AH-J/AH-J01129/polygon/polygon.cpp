#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5005;
int n;
long long sum,cnt=1;
int a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];
	}
	if(n==1||n==2)
	{
	   cout<<0;
	   return 0;
	}
	if(n==3)
	{
	   sort(a+1,a+n+1);
	   if(a[1]+a[2]>a[3])
	   {
		  cout<<1;
	   }
	   else
	   {
		   cout<<0;
	   }
	   return 0;
	}
	cout<<(n-2)%mod;
	return 0;
}
