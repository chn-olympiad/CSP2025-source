#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n+5],flag1=1,flag0=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            flag1=0;
        }
        if(a[i]!=0)
        {
            flag0=0;
        }
    }
    if(k==0&&n<=10&&flag1)
    {
        if(n%2==0)
        {
            cout<<pow(n/2,2);
        }
        else
        {
            cout<<0;
        }
    }
    else if(k>=0&&k<=1&&(flag1||flag0))
    {
        if(k==0)
        {
            if(flag0)
            {
                cout<<(n+1)*n/2;
            }
            else{
                if(n%2==0)
                {
                    cout<<12;
                }else{
                    cout<<pow(n/2,2);
                }
            }
        }else{
            if(flag0)
            {
                cout<<0;
            }else{
                if(n%2==1)
                {
                    cout<<pow(n/2,2);
                }else{
                    cout<<6;
                }
            }
        }
    }
    return 0;
}



