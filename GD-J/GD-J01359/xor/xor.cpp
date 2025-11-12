#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int ma,sum,s,n,k,i,j,a[N];
int fun(int le,int ri)
{
	int i,s=a[le];
	for(i=le+1;i<=ri;i++)
	{
		s=s^a[i];
	}
	return s;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=2)
	{
		cout<<1;
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(fun(i,j))
			{
				i=j+1;
				sum++;
				break;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
