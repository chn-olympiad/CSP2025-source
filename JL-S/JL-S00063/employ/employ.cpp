#include <bits/stdc++.h>
using namespace std;
int n,m,i,c[501],o,p,l,j,q,k;
char s[501];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(n=m)
      p=1;
    for(i=0;i<n;i++)
    {
        cin>>s[i];
        if(s[i]=='0')
          o=1;
    }
    l=1;
    for(i=0;i<n;i++)
    {
        cin>>c[i];
    }
    if(p==1&&o==1)
    {
        cout<<"0";
    }
    else if(o==0)
    {

        for(i=1;i<=n;i++)
        {
            l=l*i%998244353;
        }
        cout<<l;
    }
    else if(m==1)
    {
        if(s[0]=='1')
        {
            for(i=1;i<=n;i++)
            {
                l=l*i%998244353;
            }
            cout<<l;
        }
        else
        {
            for(i=0;i<n;i++)
            {
                if(s[i]=='1')
                {
                    for(j=0;j<n;j++)
                    {
                        if(c[j]>i)
                        {
                            q++;
                            k=1;
                        }
                    }
                    break;
                }
            }
            if(k==1)
            {
                for(i=1;i<n;i++)
                {
                    l=l*i%998244353;
                }
                l=l*q%998244353;
                cout<<l;
            }
            else
              cout<<"0";
        }
    }
    return 0;
}
/*

G
41
2025.11.1 16:57

*/
