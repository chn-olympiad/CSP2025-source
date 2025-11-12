#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int t=a[1];
    sort(a+1,a+n*m+1,cmp);
    int d=0,ans=0,i=1,j=1;
    for(int j=1;j<=m;j++)
    {
         ans++;
        if(a[ans]==t)
        {
            cout<<j<<" "<<i;
            return 0;
        }

        if(d%2==0)
        {
            for(int i=2;i<=n;i++)
            {
                 ans++;

                if(a[ans]==t)
                {
                    cout<<j<<" "<<i;
                    return 0;
                }


            }


        }
        else for(int i=n-1;i>0;i--)
        {
            ans++;
            if(a[ans]==t)
                {
                    cout<<j<<" "<<i;
                    return 0;
                }

        }
        d++;
    }
   fclose(stdin);
   fclose(stdout);
    return 0;
}
