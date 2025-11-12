#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int ans,num;
const long long N=1e6+1;
int a[N];
signed main()
{
    freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
    cin>>s;
    int m=s.size();
    for(int i=0;i<m;i++)
    {
        if(s[i]<='9')
        {
            a[num]=s[i]-'0';
            ans++;
            num++;
        }
    }
sort(a,a+ans);

   for(int i=ans-1;i>=0;i--)
   {
       cout<<a[i];
   }


    return 0;
}
