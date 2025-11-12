#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t>0)
	{
		int n;
		cin>>n;int ans=0;
		int a[n],b[n],c[n];int e=-100,g=-100,h=-100;int j,k,l;
		for(int i=0;i<n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		int f=1;int max=-100000;int d,w;int a_=0,b_=0,c_=0;
		while(f!=n)
		{
			for(int i=0;i<n;i++)
			{
				if(max<a[i])
				{
					max=a[i];
					d=i;w=0;
				}
				if(max<b[i])
				{
					max=b[i];
					d=i;w=1;
				}
				if(max<c[i])
				{
					max=c[i];
					d=i;w=2;
				}
			}
			if(w==0 && a_<n/2)
			{
				a_++;f++;ans+=max;
				a[d]=-100;b[d]=-100;c[d]=-100;
			}
			else if(w==1 && b_<n/2)
			{
				b_++;f++;ans+=max;
				a[d]=-100;b[d]=-100;c[d]=-100;
			}
			else if(w==2 && c_<n/2)
			{
				c_++;f++;ans+=max;
				a[d]=-100;b[d]=-100;c[d]=-100;
			}
			else
			{
				if(w==0)
				{
					for(int i=0;i<n;i++)
					{
						a[i]= -100;
					}
				}
				else if(w==1)
				{
					for(int i=0;i<n;i++)
					{
						b[i]= -100;
					}
				}
				else if(w==2)
				{
					for(int i=0;i<n;i++)
					{
						c[i]= -100;
					}
				}
			}
			max=-100000;
		}
		cout<<ans<<endl;
		t--;
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}
