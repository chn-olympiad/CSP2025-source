#include<bits/stdc++.h>
using namespace std;
const int N=5*100000+15;
int a[5];
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	if(k<=1)
	{
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==a[i+1])
				{
					ans+=1;
					i+=1;
				}
			}
			cout<<ans;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
