#include<bits/stdc++.h> 
using namespace std;
int n,g,l,r,number,C,D,z; 
int a[10010],b[10010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("plygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n-2;i++)
	{
		l=i+1,r=i+2;
		while(r<=n)
		{
			if(a[i]+a[l]>a[r])
			{
				number=(number+r-l)%998244353;
				//cout<<'a';
				r++;
			}
			else
			{
				if(r-l<=1)
				{
					r++;
				}
				l++;
			}
			
		}
	}
	cout<<number<<endl;
	for(int i=4;i<=n-1;i++)
	{
		for(int j=1;j<=n-i+1;i++)
		{
			l=j+1,r=j+i-1;
			while(r<=n)
			{
				if(a[j]+b[l+i-3]-b[l-1]+a[r]>a[r]*2)
				{
					C=1;
					D=1;
					z=r-l;
					int ff=i-2;
					while(ff)
					{
						C*=z;
						D*=ff;
						ff--;
					}
					C=C/D;
					number=(number+C)%998244353;
					
					r++;
				}
				else
				{
					if(r-l<=i-2)
					{
						r++;
					}
					l++;
				}
			
			}
		}
	}
	if(n!=3&&b[n]>a[n]*2)
	{
		number++;
		cout<<number<<' ';
	}
	cout<<number;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
