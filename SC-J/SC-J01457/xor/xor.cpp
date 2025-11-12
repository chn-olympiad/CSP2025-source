#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    long long n,k,sum=0,o=1;
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	for (int j=o;j<=i;j++)
    	{
    		b[j]=b[j]^a[i];
    		
    		if (b[j]==k)
    		{
    			sum++;
    			o=i+1;
    			break;
			}
		}
	}
	cout<<sum;
	return 0;
}