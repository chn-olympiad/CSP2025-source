#include<bits/stdc++.h>
#define LL long long
using namespace std;
string h;
int s[15];
signed main()
{
	//ccf is "good"
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout); 
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>h;
   for(int i=0;i<h.size();i++)
   {
   	   if(h[i]>='0'&&h[i]<='9')s[h[i]-'0']++;
   }
   for(int i=9;i>=0;i--)
   {
   	   while(s[i])cout<<i,s[i]--;
   }
  return 0;
}

