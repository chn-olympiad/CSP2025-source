#include<bits/stdc++.h>
using namespace std;
int n,m;
bool x;
int a[101];
bool flag;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+n*m,cmp);
	int c=1,r=1;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]!=t){
			if(!flag)
			    r++;
			else r--;
			if(r>n)
			{
				r=n;
				flag=!flag;
				c++;
			}
			else if(r<1)
			{
				r=1;
				flag=!flag;
				c++;
			}
		}
		else break;
	}
	cout<<c<<" "<<r; 
	return 0;
}
