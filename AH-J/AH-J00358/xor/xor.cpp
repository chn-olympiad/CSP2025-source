#include<bits/stdc++.h>
using namespace std;
int  n,k,a[500005],sum,f[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	int s[n][n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i][1]=a[i];
		if(a[i]==k)
		{
			sum++;
			f[i]=1;
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			for(int q=j;q<=i+j-1;q++)
			{
				s[j][i]=s[j][i-1]^a[q];
			}
			if(s[j][i]==k)
			{
				int b=0;
				for(int q=j;q<=i+j-1;q++)
					b+=f[q];
				if(b==0)
				{
					sum++;
					for(int q=j;q<=i+j-1;q++)
						f[q]=1;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
