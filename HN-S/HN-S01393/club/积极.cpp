#include<bits/stdc++.h>
using namespace std;

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l=min(n,m);
	int r=max(n,m);
	for(int i=l; i<=r; i++)
	{
		printf("%d  %c\n",i,(char)(i));
	}
	return 0;
}

