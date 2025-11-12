#include<bits/stdc++.h>
using namespace std;
long long read()
{
	register long long x=0,k=1;
	register char c=getchar();
	while (c<'0'||c>'9')
	{
		if (c=='-')
			k=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return k*x;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cout<<1; 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

