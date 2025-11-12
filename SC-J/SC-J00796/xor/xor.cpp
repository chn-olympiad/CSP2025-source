#include <bits/stdc++.h>
using namespace std;
const int M = 5e5+10;
int a[M];
int main()
{	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt = 0;
	cin>>n>>k;
	for(int i = 1;i<=n;i++) cin>>a[i];
	if(k==0)
	{
		for(int i = 1;i<=n;i++)
		{
			if(a[i]==0) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}