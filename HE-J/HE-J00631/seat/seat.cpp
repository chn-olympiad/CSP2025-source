#include <bits/stdc++.h>
using namespace std;
int n,m;
struct St{
	int a,l;
}a[105]; 
bool num(St a,St b)
{
	return a.a>b.a;
}
int main()
{
//	/*
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
//	 */
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].a; 
		a[i].l=i;
	}
	sort(a+1,a+n*m+1,num);
	int c=1,r=1,i=1;
	bool u=false;
	for(c=1;c<=m;c++)
	{
		while(r>=1&&r<=n)
		{
			if(a[i].l==1)
			{
				printf("%d %d",c,r);
				return 0;
			}
			if(u)
				r--;
			else
				r++;
			i++;
		}
		if(!u)
			r--;
		else
			r++;
		u=!u;
	}
	return 0;
} 
