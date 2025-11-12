#include<bits/stdc++.h>
using namespace std;
int a[15][15],n,m,r,ming[114],flag,lie,hang;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>ming[i];
    r=ming[1];
    sort(ming,ming+n*m+1);
    for(int i=n*m;i>=1;i--)
    {
        if(ming[i]==r)
        {
            flag=n*m-i+1;
            break;
        }
    }

    //cout<<flag;

    if(flag%m!=0)lie=flag/n+1;
    else lie=flag/n;


    if(lie%2==0)
    {
        flag-=(lie-1)*m;
        hang=m+1-flag;
    }
    else
    {
        flag-=(lie-1)*m;
        hang=flag;
    }
    cout<<lie<<" "<<hang;
    return 0;
}
//shengxu n hang
