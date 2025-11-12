#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q;
	int a[101];
	cin>>n>>m;
	cin>>a[1];
	int kkk=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int l=n*m;
	sort(a+1,a+l+1);
	for(int i=n*m;i>=1;i--)
		if(a[i]==kkk)
			q=i;
	int x=1;
	q=l-q+1;
	while(q>m)
	{
		x++;
		q-=m;
	}
	cout<<x<<" "<<q;
	return 0;
} 
