#include<bits/stdc++.h>
using namespace std;
int d[100005],o=0,a[100005],b[100005],c[100005],al,bl,cl,dl;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		o=0;
		al=0;
		bl=0;
		cl=0;
		dl=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
			o+=max(a[i],max(b[i],c[i]));
			if(a[i]==max(a[i],max(b[i],c[i])))
			{
				al++;
			}
			else if(b[i]==max(a[i],max(b[i],c[i])))
			{
				bl++;
			}
			else
			{
				cl++;
			}
		}
		if(al>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]!=max(a[i],max(b[i],c[i])))
				{
					continue;
				}
				dl++;
				d[dl]=a[i]-max(b[i],c[i]);
			}
			sort(d+1,d+dl+1);
			for(int i=1;i<=al-n/2;i++)
			{
				o-=d[i];
			}
			cout<<o<<endl;
		}
		else if(bl>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==max(a[i],max(b[i],c[i])) or b[i]!=max(a[i],max(b[i],c[i])))
				{
					continue;
				}
				dl++;
				d[dl]=b[i]-max(a[i],c[i]);
			}
			sort(d+1,d+dl+1);
			for(int i=1;i<=bl-n/2;i++)
			{
				o-=d[i];
			}
			cout<<o<<endl;
		}
		else if(cl>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==max(a[i],max(b[i],c[i])) or b[i]==max(a[i],max(b[i],c[i])))
				{
					continue;
				}
				dl++;
				d[dl]=c[i]-max(a[i],b[i]);
			}
			sort(d+1,d+dl+1);
			for(int i=1;i<=cl-n/2;i++)
			{
				o-=d[i];
			}
			cout<<o<<endl;
		}
		else
		{
			cout<<o<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
