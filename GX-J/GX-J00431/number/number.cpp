#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
char c;
int a[1000000+10],t=0;
int main()
{
  freopen("number.in","r",stdin);	
  freopen("number.out","w",stdout);
  while(cin>>c)
  {
	if(c>='0' && c<='9')
	{
	  t++;
	  a[t]=c-'0';	
	}
  }
  for(int i=1; i<=t-1; i++)
    for(int j=2; j<=t; j++)
      if(a[j]>a[j-1]) 
      {
		int x=a[j],y=a[j-1];
	    a[j]=y;
	    a[j-1]=x;
	  }
  for(int i=1; i<=t; i++)
    cout<<a[i];
  return 0;
}
