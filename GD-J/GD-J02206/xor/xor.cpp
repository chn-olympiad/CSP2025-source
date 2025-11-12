#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,k;
int a[N];
int x[N];
int get(int l,int r)
{
	if(l>r)return -1;
	return x[r]^x[l-1];
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	freopen("xor0.in","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		x[i]=x[i-1]^a[i];
	}
	int last=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		if(get(last+1,i-1)==get(last+1,i))
			continue;
		for(int j=last+1;j<=i;j++)
		{
			if(get(j,i)==k)
			{
//				cout<<j<<" "<<i<<"]\n";
				last=i,sum++,j=last+1;
			}
		}
	}
	cout<<sum;
	return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/
