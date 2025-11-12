#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long Diff[500010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	Diff[0]=0;
	for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			Diff[i]=(Diff[i-1]|a[i]);
		}
	long long ans=0,f=0;
	for(int i=f;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			if(((Diff[j]-Diff[i-1])==k || Diff[j]-Diff[j-1]==k) && i!=j)
			{
				f=j+1;
				ans++;
				break;
			}	
		}
	cout<<ans<<endl;
	return 0;
}

