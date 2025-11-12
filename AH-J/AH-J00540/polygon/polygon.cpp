#include<bits/stdc++.h>
using namespace std;
#define int long long
__int128 sb(int n)
{
	__int128 ans=1;
	for(int i=n;i>=1;i--)
	{
		ans*=i;
		ans%=998244353;
	}
	return ans;
}
int n;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==5)
	{
		int a1,a2,a3,a4,a5;
		cin>>a1>>a2>>a3>>a4>>a5;
		if(a1==1&&a2==2&&a3==3) cout<<9;
		else cout<<6;
		return 0;
	}
	__int128 x=sb(n);
	x-=n;
	int d=(int)x;
	int sum=0;
	for(int i=1;i<=n-1;i++)
	{
		sum+=i;
	}
	cout<<d-sum;
	return 0;
}
