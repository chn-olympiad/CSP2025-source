#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,a[N],qzh[N],qyh=-1;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	cin>>a[1];qzh[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		qzh[i]=qzh[i-1]^a[i];
		
	}
	bool only_one;
	int ans=0;
		for(int i=1;i<=n;i++)
		{
			only_one=1;
			if(qyh!=-1)qzh[i]^=qyh;
			if(qzh[i]==k)
			{
				ans++;
				if(qyh==-1)qyh=k;
				else qyh^=k;
				only_one=0; 
			}
			if(a[i]==k&&only_one)
			{
				ans++;
				if(qyh==-1)qyh=qzh[i];
				else qyh^=qzh[i];
			}
		}
	cout<<ans;
	return 0;
}
