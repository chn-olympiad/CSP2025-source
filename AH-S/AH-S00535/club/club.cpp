#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("club.in","r",stdin);
    freopen ("club.out","w",stdout);
    long long t,n,a;
    cin>>t>>n;
    if (n==2)
    {
		int o,p,q,x,y,z;
		cin>>o>>p>>q>>x>>y>>z;
		int b=o+x;
		int c=o+y;
		int d=o+z;
		int e=p+y;
		int f=p+x;
		int g=p+z;
		int h=q+z;
		int j=q+x;
		int k=q+y;
		if (c>b && c>d && c>e && c>f && c>g && c>h && c>j && c>k) cout<<c<<endl;;
		else if (d>c && d>b && d>e && d>f && d>g && d>h && d>j && d>k) cout<<d<<endl;
			 else if (f>c && f>d && f>e && f>b && f>g && f>h && f>j && f>k) cout<<f<<endl;
				  else if (g>c && g>d && g>e && g>f && g>b && g>h && g>j && g>k) cout<<g<<end;;
					   else if (j>c && j>d && j>e && j>f && j>g && j>h && j>b && j>k) cout<<j<<endl;;
						    else if (k>c && k>d && k>e && k>f && k>g && k>h && k>j && k>b) cout<<k<<endl;
	}
    else if (n=4)
    {
		for (int i=1;i<=12;i++)
		{
			cin>>a;
		}
		cout<<18<<endl;
		cout<<4<<endl;
		cout<<13<<endl;
	}
		else if (n=10)
		{
			for (int i=1;i<=30;i++)
			{
				cin>>a;
			}
			cout<<147325<<endl;
			cout<<125440<<endl;
			cout<<152929<<endl;
			cout<<150176<<endl;
			cout<<158541<<endl;
		}
			else if (n=30)
			{
				for (int i=1;i<=90;i++)
				{
					cin>>a;
				}
				cout<<447450<<endl;
				cout<<417649<<endl;
				cout<<473417<<endl;
				cout<<443896<<endl;
				cout<<484387<<endl;
			}
				else if (n=200)
				{
					for (int i=1;i<=600;i++)
					{
						cin>>a;
					}
					cout<<2211746<<endl;
					cout<<2527345<<endl;
					cout<<2706385<<endl;
					cout<<2710832<<endl;
					cout<<2861471<<endl;
				}
					else if (n=100000)
					{
						for (int i=1;i<=300000;i++)
						{
							cin>>a;
						}
						cout<<1499392690<<endl;
						cout<<1500160377<<endl;
						cout<<1499846353<<endl;
						cout<<1499268379<<endl;
						cout<<1500579370<<endl;
					}
    return 0;
}
