#include<bits/stdc++.h>
using namespace std;
int n,m,a,num=1,b;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a;
	for(int i=1;i<n*m;i++)
	{
		cin>>b;
		if(b>a) num++;
	}
	int c=num/n,r=num%n;
	if(num%n>0) c++;
	if(c%2==0) r=n-num%n+1;
	if(r==0) r=n;
	cout<<c<<" "<<r;
	
	return 0;
}
/*
100 97
99  98
98 99 100 97
2
*/
