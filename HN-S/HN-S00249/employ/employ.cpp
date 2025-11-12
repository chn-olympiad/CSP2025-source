//#include<bits/stdc++.h>
//typedef int int32;
//#define int long long
//using namespace std;
///*
//	Author: wbw_121124
//	人杰地灵
//	employ.cpp
//	
//	不会是#@$^^%^%$$%$#^$%#$%#^$%%^^$ 
//*/
//const int N = 500 + 5, mod = 998244353;
//int n,m,a[N],b[N],ans;
//string s;
//signed main()
//{
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
//	cin>>n>>m>>s;
//	s='#'+s;
//	for(int i=1;i<=n;i++)
//		cin>>a[i],b[i]=i;
//	do
//	{
//		int sum=0;
//		for(int i=1;i<=n;i++)
//			if(s[i]=='0')
//				sum++;
//			else if(a[b[i]]<=sum)
//				sum++;
//		if(n-sum>=m)
//			ans=(ans+1)%mod;
//	} while(next_permutation(b+1,b+1+n));
//	cout<<ans;
////	cerr<<clock()<<'\n';
//	return 0;
//}
#include<bits/stdc++.h>
typedef int int32;
#define int long long
using namespace std;
/*
	Author: wbw_121124
	人杰地灵
	employ.cpp
	
	不会是#@$^^%^%$$%$#^$%#$%#^$%%^^$ 
*/
const int N = 500 + 5, mod = 998244353;
int n,m,a[N],b[N],ans;
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m>>s;
	s='#'+s;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=i;
	if(n==m)
	{
		ans=1;
		for(int i=1;i<=n;i++)
			ans=ans*i%mod;
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||!a[i])
				ans=0;
		cout<<ans;
		return 0;
	}
	do
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0')
				sum++;
			else if(a[b[i]]<=sum)
				sum++;
		if(n-sum>=m)
			ans=(ans+1)%mod;
	} while(next_permutation(b+1,b+1+n));
	cout<<ans;
//	cerr<<clock()<<'\n';
	return 0;
}
