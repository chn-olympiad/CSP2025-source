#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	 int n,k,b=0,c=0,d=-1;
	 cin>>n>>k;
	 for(int i=0;i<n;i++)
	 {
	 	cin>>a[i];
	 	if(a[i]==k)
		{
			c++;
			d=i+1;
		}
		else if(d<i)
		{
			a[i]=a[i]^a[i-1];
			if(a[i]==k)
			{
				c++;
				d=i+1;
			}
		}
	}
	cout<<c;
	return 0;
}
