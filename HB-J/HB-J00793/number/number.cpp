#include<iostream>
#include<cstdio>
using namespace std;
char a[1000005]={0}; int b[1005]={0},sum,book,s;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
for(int i=0;int(a[i])>0;i++)
{
	if(int(a[i])>48&&int(a[i])<58)
	{
		b[sum]=a[i];
		sum++;
	}
}
for(int i=0;i<sum;i++)
{
	s=0; book=0;
	for(int i=0;i<sum;i++)
    {
	    if(b[i]>s)
	    {
		    s=b[i];
		    book=i;
	    }
    }
    b[book]=0;
    cout<<s-48;
}
return 0;
}
