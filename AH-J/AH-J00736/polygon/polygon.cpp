#include<bits/stdc++.h>
using namespace std;
int n,ans,a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	if(n==3)
	{
		for(int i=0;i<n;i++)
		    for(int j=i+1;j<n;j++)
		        for(int k=j+1;k<n;k++)
		        {
					if(a[i]+a[j]+a[k]>2*a[k]) ans++;
				}
    }	
	cout<<ans;
	return 0;
}
