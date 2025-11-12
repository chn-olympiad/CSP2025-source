#include<bits/stdc++.h>
using namespace std;
string s;
char n[1000001];
int a[1000001],i,c,j;
long long t,q,u;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>t;
    if(t<=11)
      cout<<t;
    else
    {
        q=1;
        u=1;
        for(i=0;i<101;i++)
        {
            q=q*10;
            if(i!=0)
              u=u*10;
            a[i]=t%q/u;
            c++;
            if(q>t)
              break;
        }
        for(i=0;i<c-1;i++)
        {
            for(j=i+1;j<c;j++)
            {
                if(a[i]<a[j])
                  swap(a[i],a[j]);
            }
        }
        for(i=0;i<c;i++)
        {
            cout<<a[i];
        }
    }
    return 0;
}
