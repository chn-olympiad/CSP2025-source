#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

const int M=100005;

int t;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		int n,a1[M],a2[M],a3[M],a=0,b=0,c=0,ans[M][4]={},s=0,x=0,x1=0,x2=0,x3=0,x4=0,x5=0;
		int t[M]={};
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]==0&&a3[i]==0)	x++;
			if(a1[i]==0&&a3[i]==0)	x1++;
			if(a2[i]==0&&a1[i]==0)	x2++;
			if(a1[i]==0)	x3++;
			if(a2[i]==0)	x4++;
			if(a3[i]==0)	x5++;
			if(a1[i]>a2[i]&&a1[i]>a3[i])
			{
				ans[i][1]=a1[i];
				a++;
				t[i]==1;
			}				
			else if(a2[i]>a1[i]&&a2[i]>a3[i])
			{
				ans[i][2]=a2[i];
				b++;
				t[i]==2;
			}
			else
			{
				ans[i][3]=a3[i];
				c++;
				t[i]==3;
			}
			
		}	
		if(x==n)
		{
			sort(a1,a1+n+1);
			x=n/2;
			for(int i=n;i>x;i--)
			{
				s=s+a1[i];
			}
			cout<<s<<endl;
			
		}
		else if(x1==n)
		{
			sort(a2,a2+n+1);
			x=n/2;
			for(int i=n;i>x;i--)
			{
				s=s+a2[i];
			}
			cout<<s<<endl;
			
		}
		else if(x2==n)
		{
			sort(a3,a3+n+1);
			x=n/2;
			for(int i=n;i>x;i--)
			{
				s=s+a3[i];
			}
			cout<<s<<endl;
			
		}
//		else if(x3==n)
//		{
//			
//		}
		else if(a<=n/2)
		{
			if(b<=n/2)
			{
				if(c<=n/2)
				{
					for(int i=1;i<=n;i++)
					{
						s=s+ans[i][1]+ans[i][2]+ans[i][3];
					}	
					cout<<s<<endl;
				}
				else
				{
//					for(int i=1;i<=n;i++)
//					{
//						if(t[i]==3)
//						
//					}
				}
			}
		}
	}
	return 0;
}
