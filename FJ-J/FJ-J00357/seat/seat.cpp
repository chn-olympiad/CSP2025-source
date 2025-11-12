#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,m;
int a[101];
int map[101][101];
int cmp(int x,int y)
{
	return x>y;
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
	
	if(n==1&&m==1)
	{
		cout<<"1 1";
		return 0;
	}
	
	int p=a[1];
	int q;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
		{
			q=i;
			break;
		}
	}
	if(m==1)
	{
		cout<<q<<" 1";
		return 0;
	}
	
	//ÊÔÑé 
//	cout<<endl;
//	cout<<p<<endl;
//	for(int i=1;i<=n*m;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
//	cout<<q<<" "<<n; 

	int l;
	if(q%n==0)
	{
		cout<<q/n<<" ";
		l=q/n;
	}
	else
	{
		cout<<q/n+1<<" ";
		l=q/n+1;
	}
	if(l%2==1) cout<<q-(l-1)*n;
	else cout<<n-(q%n)+1;
	return 0;
}
