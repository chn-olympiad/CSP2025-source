#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000001],k,ans,an,ma=-1,mi=5e5+5;
int b[1000001];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{b[i]=1;ans++;
			
		}
		if(a[i]==1)an++;

	}
    int sum=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=1)
		{
			sum^=a[i];
			if(sum==k)
			{
				ans++;sum=0;
			}
		}else{

			sum=0;			
		}
	}if(sum==k&&k!=0)ans++;
	cout<<ans;
	return 0;
}
/*

100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0
1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 
1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 
0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 
0 1 1 1 0 1 0 1 0 1 0 1 1 1 0
1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 
0 1 0 1 1 0 0 0 0 1
*/

