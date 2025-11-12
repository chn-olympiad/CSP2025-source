//GZ-S00119 贵阳市清华中学 喻宥诚 
#include<bits/stdc++.h>
using namespace std;
typedef long long lol;
lol a=1,n;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a*=i;
		a=a%998244353;
	}
	cout<<a;
	return 0;
}
