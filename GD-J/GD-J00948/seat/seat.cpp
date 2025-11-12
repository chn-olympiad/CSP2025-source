#include<iostream>
#include <algorithm>
using namespace std;

int n,m,k,l,p,a[100],b[10][10];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i)
		for(int j=1;j<=m;++j)
			cin>>a[i*n+j];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=m;++i)
	{
		if(i%2)
		{
			l=1;
			while(l<=n)
			{
				b[l][i]=a[++p];
				if(b[l][i]==k)
				{
					cout<<i<<" "<<l;
					return 0;
				}
				++l;
			}
		}
		else
		{
			l=n;
			while(l>=1)
			{
				b[l][i]=a[++p];
				if(b[l][i]==k)
				{
					cout<<i<<" "<<l;
					return 0;
				}
				--l;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
