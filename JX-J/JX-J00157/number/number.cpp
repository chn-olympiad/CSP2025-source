#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
   int n=0;
   string s;
   cin>>s;
   int k=0;
   while((s[k]>='a'&&s[k]<='z')||(s[k]>='0'&&s[k]<='9'))
   {
		  
	  if(s[k]>='0'&&s[k]<='9')
	  {
		 a[n]=s[k]-48;
	     n++;
      } 
	   k++;
   }
   sort(a,a+n);
   for(int i=n-1;i>=0;i--)cout<<a[i];
   return 0;
}
