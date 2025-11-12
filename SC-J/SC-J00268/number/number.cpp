#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int b[N],c[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int cnt=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>=48&&a[i]<=57)
		{
			b[cnt]=int(a[i]-48);
			cnt++;
		}
	}
	for(int i=0;i<cnt;i++)
	{
		c[i]=-1;
	}
	for(int i=0;i<cnt;i++)
	{
		int ans=-1,s=0;
		for(int j=0;j<cnt;j++)
		{
			if(b[j]!=c[j])
			{
				if(b[j]>=ans)
				{
					ans=b[j];
					s=j;
				}
			}
		}
		c[s]=ans;
		cout<<ans;
	} 
	return 0;
}