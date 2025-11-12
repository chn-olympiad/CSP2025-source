#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[105],s,r,r_book;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++){cin>>a[i*m+j];}
	}
	r=a[0];
	for(int i=0;i<n*m;i++)
	{
		if(a[i]<a[i+1])
		{
			s=a[i];
			a[i]=a[i+1];
			a[i+1]=s;
		}
	}
	for(int i=0;i<n*m;i++)
    {
        if(a[i]==r)
            r_book=i+1;
    }
	if(r_book%n==0)
    {
        cout<<r_book/n<<" ";
        if(r_book/n%2==0){cout<<1;}
        else{cout<<n;}
    }
    else
    {
        cout<<r_book/n+1<<" ";
        if(r_book/n%2==0){cout<<r_book%n;}
        else{cout<<n-r_book%n+1;}
    }
	return 0;
}
