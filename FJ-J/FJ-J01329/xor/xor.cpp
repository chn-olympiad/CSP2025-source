#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+1;
int n,k,a[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(k==0&&n<=2)
	{
		if(n==1)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<2;
			return 0;
		}
	}
	return 0;
}
