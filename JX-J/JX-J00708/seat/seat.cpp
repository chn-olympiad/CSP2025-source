#include<bits/stdc++.h>
using namespace std;
long long a,b,sum;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>b;
    long long c[a*b];
    cin>>c[0];
    for(int i=1;i<a*b;i++)
        {
            cin>>c[i];
            if(c[i]>c[0])
                sum++;
            }
    sum++;
    if(sum%a==0)
        {cout<<sum/a<<" ";
        int g=sum/a;
        if(g%2==0)
            cout<<"1";
        else cout<<a;
        }
    else
    {
        cout<<sum/a+1<<" ";
        int gh=sum/a+1,kl=sum%a;
        if(gh%2==0)
            cout<<a-kl+1;
        else cout<<kl;
    }
}
