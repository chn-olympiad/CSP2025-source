#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);
   int n,m,ans=0;
   string s;
   bool b=false;
   int c[1000];
   cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)
        cin>>c[i];
    for(int i=0;i<=s.size()-1;i++)
    {
        if(s[i]=='0')
            b=true;

    }

    if(b==false)
    {
        cout<<m;

    }
    else if(b==true&&m==1)
    {

       for(int i=0;i<=s.size()-1;i++)
       {


          if(s[i]=='1'&&c[i]>=i+1)
          {
              cout<<"1";
              return 0;
          }

       }
         cout<<"0";
         return 0;

    }
    else if(b==true&&m==n)
    {int r=0;
        for(int i=0;i<=s.size()-1;i++)
       {


          if(s[i]=='1'&&c[i]>=i-r-1)

          {

              ans++;
          r=i;
          }

       }
       cout<<ans;
       return 0;


    }
    return 0;
}
