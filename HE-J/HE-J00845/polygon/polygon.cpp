#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,a[N],cnt;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>maxn)
		{
			maxn=a[i];
		}
	}
	if(a[1]+a[2]+a[3]>maxn*2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
    fclose(stdin);
	fclose(stdout);
	return 0;
}
