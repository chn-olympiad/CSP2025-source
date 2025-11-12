#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10],x=0,lo;
int main()
{
	 freopen("number4.in","r",stdin);
	 //freopen("number.out","w",stdout);
     cin>>s;
     lo=s.size();
     for(int i=0;i<lo;i++)
     {
          if(s[i]>='0'&&s[i]<='9')
          {
               a[s[i]-'0']++;
          }
     }
     for(int i=9;i>=0;i--)
     {
		 for(int j=1;j<=a[i];j++)
		   cout<<i;
	 }
     return 0;
}
