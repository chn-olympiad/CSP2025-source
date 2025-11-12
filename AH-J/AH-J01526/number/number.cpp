#include<bits/stdc++.h>
using namespace std;
string s,str;
int main()
{
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   cin>>s;
   int l=s.size();
   for(int i=0;i<l;i++)
   {
	   if(s[i]>='0'&&s[i]<='9') str+=s[i];
   }                          
   sort(str.begin(),str.end());
   for(int i=str.size()-1;i>=0;i--) cout<<str[i];
   return 0;
}
