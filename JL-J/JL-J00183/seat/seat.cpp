#include<bits/stdc++.h>
using namespace std;
int a[110],n,m,b[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n*m;i++)
    {
        b[a[i]]++;
    }
    int k=a[1];
    int i=101,sum;
    while(1)
    {
        if(i==k)
        {
            break;
        }
        else
        {
            if(b[i]>0)
            {
                sum++;
            }
            i--;
        }

    }
    if(sum%m==0)
        cout<<sum/m<<" "<<m;
    else
        cout<<(sum/m)+1<<" "<<sum%m;

}
