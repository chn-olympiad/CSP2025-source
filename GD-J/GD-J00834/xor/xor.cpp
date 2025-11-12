#include<bits/stdc++.h>
using namespace std;
unsigned long long a[500009],b[500009];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	b[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		//cout<<b[i]<<" ";
	}
	//cout<<endl;
	long long ans=0,d=0;
	for(int i=1;i<=n;i++)
	{
		int v=0;
		int mini=500059;
		for(int j=d;j<=i;j++)
		{
			
			if((b[j]^b[i])==k&&i>j)
			{
				//cout<<j+1<<" "<<i<<" "<<(b[d]^b[i])<<endl;
				v=1;
				mini=min(mini,i);
			}
		}
		if(v)
		{
			ans++;
			d=mini;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
