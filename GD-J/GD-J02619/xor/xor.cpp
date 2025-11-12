#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	unsigned long long list[n+1];
	list[0] = 0;
	for(int i = 1;i <= n;++i)
	{
		cin>>list[i];
		list[i]^=list[i-1];
	}
	int cnt = 0;
	int ans = 0;
	for(int i = 1;i <= n;++i)
	{
		for(int j = cnt;j < i;++j)
		{
			if((list[i]^list[j])==k)
			{cnt = i;++ans;break;}
		}
	}cout<<ans;
}
