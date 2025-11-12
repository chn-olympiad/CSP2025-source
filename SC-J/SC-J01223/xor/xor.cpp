#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,s[N],t,g=0,ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		s[i]=s[i-1]^t;
	}
	int l=1,r,f=0;
	while(l<=n)
	{
		for(r=l;r<=n;r++)
		{
			g=s[r]^s[l-1];
			if(g==k)
			{
				ans++;
				f=r;
				break;
			}
		}
		l=f+1;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}