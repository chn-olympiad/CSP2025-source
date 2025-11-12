#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1010],num=0,c=1;
	cin>>s;
	int len=s.size();
    for(int i=1;i<=len-1;i++)
	  if(s[i]>='0' && s[i]<='9')
	  {
	    a[++c]=s[i];
	    num++; 
	  }
	for(int i=1;i<=num;i++)
	  if(a[i]<a[i+1])
	    swap(a[i],a[i+1]);
	for(int i=1;i<=num;i++)
      cout<<a[i];	
	return 0;
}
