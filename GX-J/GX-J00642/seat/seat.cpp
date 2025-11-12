#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n,m;
int a[n*m];
int c,r;
int main()
{
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n*m;i++)
			cin>>a[i];
		s+=a[0];
		for(int i=1;i<=n*m;i++)
		{
				if(a[i]<a[i+1])
					swap(a[i],a[i+1]);
		}
		cout<<c<<r;
		return 0;
}

