#include<bits/stdc++.h>
using namespace std;
int a[500010],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int f=1;
	for(;f<=n;f++)
		for(int e=f;e<=n;e++)
		{
			int p=0;
			for(int k=f;k<=e;k++)
				p^=a[k];
			if(p==m)ans++,f=e+1;
		}
	cout<<ans<<endl;
	return 0;
}
