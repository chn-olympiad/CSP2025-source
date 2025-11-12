#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,len;
int a[N];
int num;
int c=1,r=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++)cin>>a[i];
	num=a[1];
	sort(a+1,a+1+len);
	int i=len;
	while(a[i]!=num)
	{
		if(c%2)
		{
			r++;
			if(r>n)r=n,c++;
		}
		else
		{
			r--;
			if(r<1)r=1,c++;
		}
		i--;
	}
	cout<<c<<" "<<r;
	return 0;
}
