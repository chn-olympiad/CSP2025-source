#include<bits/stdc++.h>
using namespace std;
int n,m;
int h,w;
int grade;
int a[1100];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
		cin>>a[i];
	grade=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
		if (a[i]==grade)
		{
			h=(i-1)/n+1;
			w=i%n;
			//cout<<i<<endl;
			//cout<<h<<' '<<w<<endl;
			if (w==0)
			{
				if (h%2==0)
					w=1;
				else
					w=n;
			}	
			else
			{
				if (h%2==0)
					w=n-w+1;
			}	
			cout<<h<<' '<<w;
			return 0; 
		}
	return 0;
} 
/*
8:56 Finish OK
10:33 Check OK
*/ 
