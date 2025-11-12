#include<bits/stdc++.h>
using namespace std;
int n,k,a[5000010],ans;
bool v[5000010],f;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			int sum=a[i];
			for(int k=i+1;k<=j;k++)
				sum=sum^a[k];
			f=0;
			if(sum==k)
			{
				for(int l=i;l<=j;l++)
					if(v[l]==1)
						f=1;
				if(!f) ans++;
				for(int l=i;l<=j;l++)
					v[l]=1;
			}	
		}
	cout<<ans;
	return 0;
}
