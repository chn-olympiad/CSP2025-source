#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],x=1,y,c=0,ans = 0,b=1,d[30],d1[30],d2[30];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = i;j<n;j++)
		{
			while (a[i] >= 0&&c>=0)
			{
				c--;
				cout<<"c"<<c<<endl;
				for(int k = 1;k<=c;k++)
				{
					b *= 2;
				}
				if (b<a[i])
				{
					a[j] -= b;
					d[c] = 1;
				}
				b = 1;
			}
			while (a[j] >= 0&&c>=0)
			{
				c--;
				cout<<"c"<<c<<endl;
				for(int k = 1;k<=c;k++)
				{
					b *= 2;
				}
				if (b<a[j])
				{
					a[j] -= b;
					d1[c] = 1;
				}
				b = 1;
			}
			for(int l = 0;l<=20;l++)
			{
				if (d1[l] != d[l]) d2[l] = 1;
			}
			for(int m = 0;m<=30;m++)
			{
				for(int n = 1;n<=m;m++) x *= 2;
				y += d2[m]*x;
			}
			if (y == k) ans++;
			x = 1;y = 0;
		}
	}
	cout<<ans;//不会做小生没招了 
	return 0;
}

