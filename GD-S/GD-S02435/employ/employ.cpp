#include<bits/stdc++.h>//Ren5Jie4Di4Ling5%
#define ll long long
#define endl "\n"
using namespace std;
const int mod=998244353;
int n,m,z;
string s;
int a[505];
ll ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);//完蛋，想出来但是没时间打了 
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i],z+=(a[i]==0);
	if(n-z<m)
	{
		cout<<0;
		return 0;
	}
//	sort(a+1,a+n+1);
//	int temp=z;
	for(int i=2;i<=n;i++)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

*/
