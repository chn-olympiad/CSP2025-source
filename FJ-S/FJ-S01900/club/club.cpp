#include<bits/stdc++.h>
using namespace std;
long long a[100+10],b[100+10],c[100+10],zd[100000+10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long  t,n,d,e=0,f=0,g=0,o=0,p=0,q=0;
	cin>>t;
	while(t--)
	{
		e=0,f=0,g=0,o=0,p=0,q=0;
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=1; i<=n; i++)
		{
			d=max(max(a[i],b[i]),c[i]);
			if(e<=(n/2)||f<=(n/2)||g<=(n/2))
				{
					;
				}
				else
				{
					if(e>=(n/2))
					{
						a[i]=0;
					}
					else if(f>=(n/2))
					{
						b[i]=0;
					}
					else if(f>=(n/2))
					{
						c[i]=0;
					}
				}
			if(d==a[i])
			{
				o+=a[i];
				e++;

			}
			else if(d==b[i])
			{
				p+=b[i];
				f++;

			}
			else if(d==c[i])
			{
				q+=c[i];
				g++;
				
			}
			//cout<<(d==a[i])<<" "<<(d==b[i])<<" "<<(d==c[i])<<endl;
			//cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;

		}
		//cout<<o<<" "<<p<<" "<<q<<endl;
		if(e<=(n/2)||f<=(n/2)||g<=(n/2))
		{
			cout<<o+p+q;/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1*/
		}
	}
	return 0;
}
