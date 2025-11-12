#include<bits/stdc++.h>
using namespace std;
int n,a[500005],s[500005],k,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;)
		for(int j=i;j<=n;j++)
		{
			if((s[i-1]^s[j])==k)
			{
				i=j+1;
				ans++;
				break;
			}
			else if(j==n)
				i++;
		}
	cout<<ans;
}
