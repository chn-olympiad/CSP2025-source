#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,a,b,c,aa[4],bb[4],cc[4],t,q;
	int ans=0;
	cin>>t;
	for(int r=1;r<=t;r++)
	{

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>aa[i];
		cin>>bb[i];
		cin>>cc[i];
	}
	for(int i=1;i<=n;i++)
	{
		q=max(max(aa[i],bb[i]),cc[i]);
		ans=ans+q;
		if(aa[i]==bb[i]&&aa[i]==cc[i])
		{
			if(a==b&&b==c)
			{
				a++;
			}
			else if(a<b&&b==c)
			{
				a++;
			}
			else if(a<b&&a==c)
			{
				c++;
				//
				}
			else if(a<b&&a<c)
			{
				a++;
			}
			else if(b<a&&b<c)
			{
				b++;
				
			}
			else if(c<b&&c<a)
			{
				c++;
				}
			else if(b<a&&b==c)
			{
				b++;
			}
			else if(b<a&&a==c)b++;
			else if(c<a&&a==b)c++;
			else if(b<c&&b==a)b++;
				
		}
		else if(aa[i]>bb[i]&&aa[i]>cc[i])a++;
		else if(aa[i]==bb[i]&&aa[i]>cc[i])a++;
		else if(aa[i]==bb[i]&&aa[i]<cc[i])c++;
		else if(bb[i]>aa[i]&&bb[i]>cc[i])b++;
		else if(aa[i]==cc[i]&&aa[i]>bb[i])c++;
		else if(aa[i]==cc[i]&&aa[i]<bb[i])b++;
		else if(cc[i]>>aa[i]&&cc[i]>>bb[i])c++;
		else if(bb[i]==cc[i]&&aa[i]<bb[i])b++;
		else if(bb[i]==cc[i]&&aa[i]>bb[i])a++;
	}
	cout<<ans<<endl;
	a=0;
	b=0;
	c=0;
	n=0;
	ans=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
