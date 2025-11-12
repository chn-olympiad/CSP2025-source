#include<bits/stdc++.h>
using namespace std;
long long t[1000005],s;
bool tmp(long long x,long long y)
{
	return x>y;
}		
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
   string a;
   cin>>a;
   int m=a.size();
   for(int i=0;i<m;i++){
	   if(a[i]>='0'&&a[i]<='9')
	   t[++s]=int(a[i]-'0');
   }
   sort(t+1,t+1+s,tmp);
   for(int i=1;i<=s;i++)
      cout<<t[i];
   return 0;
}
