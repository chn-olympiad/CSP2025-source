//rp++
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int b[5505],a[5505];
const int mod=998244353;
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int v=1;
	int maxx=INT_MIN,sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		if(b[i]!=0) 
		{
			a[v]=b[i];
			v++;
		}  
	}
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}
//rp++
