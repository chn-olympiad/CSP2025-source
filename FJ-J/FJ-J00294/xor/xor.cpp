#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long n,k,s=0;
	long l=INT_MIN,r=INT_MIN,a[500000];
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int w=0;
		for(int j=i;j<n;j++)
		{
			w^=a[j];
			if(w==k)
			{
				if(j<=r)
				{
					l=i;
					r=j;
				}
				else
				{
					l=i;
					r=j;
					s++;
					break;
				}
			}
		}
	}
	cout<<s<<endl;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
