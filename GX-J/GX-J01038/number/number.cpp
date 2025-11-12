#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,b;
    cin>>s;
    long long a,d[1000001];
    a=s.size();
    for(int i=0;i<a;i++)
   {
	   if(s[i]>='0'&&s[i]<='9')
	   {
		   b=b+s[i];
	   }
   }
   int c=b.size();
    for(int i=0;i<c;i++)
   {
	   d[i]=int(b[i])-48;
   }
   sort(d,d+c);
   for(int i=c-1;i>=0;i=i-1)
   {
	   cout<<d[i];
   }
    return 0;
}
