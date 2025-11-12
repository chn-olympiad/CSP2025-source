#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m,s[507],ans=1,cnt;
int main()
{
   freopen("employ.in","r",stdin);
   freopen("employ.out","w",stdout);
   cin>>n>>m;
   string a;
   cin>>a;
   cnt=n;
   for(int i=1;i<=n;i++)
   {
	   cin>>s[i];
   }
   for(int i=n;i>=m;i--)
   {
	   ans*=i;
	   ans%=mod;
   }	
   cout<<ans;
   return 0;
}
