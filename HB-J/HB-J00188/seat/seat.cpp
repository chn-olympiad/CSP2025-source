#include<bits/stdc++.h>
using namespace std;
int an=1,am=1;
int a[1010],b[1010];
int n,m;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+n*m+1);
    int b1=0;
    for(int i=n*m;i>=1;i--)
    {
        b1++;
        b[b1]=a[i];
    }
    for(int i=1;i<=n*m;i++)
    {
        if(b[i]==r)//---------------
        {
            cout<<am<<" "<<an;
            break;
        }//---------------
        if(an==1&&am%2==0)
        {
            am++;
            continue;
        }
        if(an==n&&am%2==1)
        {
            am++;
            continue;
        }
        if(am%2==1)
        {
            an++;
            continue;
        }
        else if(am%2==0)
        {
            an--;
            continue;
        }
    }
    return 0;
}
