#include<bits/stdc++.h>
using namespace std;
string st;
long long t,f[1005],n;
int main()
{
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout); 
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);       
   cin>>st;
   n=st.size();
   for(int i=0;i<n;i++)
   {
	   if(st[i]>='0'&&st[i]<='9')
       {
		   t=st[i]-'0';
		   f[t]++;
	   }
   }
   for(int i=9;i>=0;i--)
   {
	   for(int j=1;j<=f[i];j++)
	   {
		   cout<<i;
	   }
   }
   return 0;
}
