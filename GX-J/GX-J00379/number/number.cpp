#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s;
int a[500100],cnt;
bool cmp(int x,int y)
{
  return x>y;	
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>s)
    {
      if(s=='0') a[++cnt]=0;
      if(s=='1') a[++cnt]=1;
      if(s=='2') a[++cnt]=2;
      if(s=='3') a[++cnt]=3;
      if(s=='4') a[++cnt]=4;
      if(s=='5') a[++cnt]=5;
      if(s=='6') a[++cnt]=6;
      if(s=='7') a[++cnt]=7;
      if(s=='8') a[++cnt]=8;
      if(s=='9') a[++cnt]=9;
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	  cout<<a[i];
    return 0;
}
