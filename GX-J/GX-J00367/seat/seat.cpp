#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    long long n,m,a[101],s;
    cin>>m>>n;
    int x=n*m;
    cin>>s;
    a[1]=s;
    for(int i=2;i<=x;i++)
		cin>>a[i];
    sort(a+1,a+x+1);
    for(int i=x;i>=1;i--)
    {
		if(a[i]==s)
		{
		   if(i%m==0)
		     cout<<i/m<<" "<<m;
		   else
		     cout<<i/m+1<<" "<<i%m;
		}
	}
	return 0;
}

