#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	return x>y;
} 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h=1,l=1,m,n,a[122]={0},o,g=1,keeper=0;
	cin>>n>>m;
	for(int i=1;i<=(m*n);i++)
		cin>>a[i];
	o=a[1];
	sort(a+1,a+(m*n)+1,cmp);
	while(keeper==0)
	{
		while(l<=n)
		{
			g++;
			l++;
			if(a[g]==o)
			{
				keeper=1;
				break;
			}
		}
		h++;
		l--;
		if(keeper==1)
			break;
		while(l>=1)
		{
			g++;
			l--;
			if(a[g]==o)
			{
				keeper=1;
				break;
			}
		}
		h++;
		l++;
	}
	cout<<h<<" "<<l;
}
