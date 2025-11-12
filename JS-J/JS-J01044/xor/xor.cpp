#include<bits/stdc++.h>
using namespace std;
int n,k,tp,sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1,a;i<=n;i++)
	{
		cin>>a;
		tp=(tp^a);
		if(tp==k)
		{
			tp=0;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
