#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	bool p=0;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		if(a[i]!=0 && a[i]!=1) p=1;
	}
	if(!p)
	{
		int l=1,x=-1;
		while(l<=n)
		{
			if(x==-1) x=a[l];
			else x^=a[l];
			if(x==k) ans++,x=-1;
			l++;
		}
	}
	else
	{
		int l=1,x=-1,nxt;
		while(l<=n)
		{
			if(x==-1) x=a[l],nxt=l;
			else x^=a[l];
			if(x==k)
			{
				ans++;
				int m=l;
				for(int i=nxt+1;i<l;i++)
				{
					int s=-1;
					for(int j=i;j<l;j++)
					{
						if(s==-1) s=a[j];
						else s^=a[j];
						if(s==k)
						{
							m=min(m,j);
							break;
						}
					}
				}
				x=-1,l=m+1;
			}
			else l++;
		}
	}
	printf("%d",ans);
	return 0;
}
