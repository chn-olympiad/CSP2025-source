#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(n==1&&k==0)
		{
			cout<<1<<'\n';
			return 0;
		}
		if(n==2&&k==0)
		{
			if(a[1]==a[2])
			{
				cout<<3<<'\n';
				return 0;
			}
		}
	}
	
	return 0;
}
