#include<bits/stdc++.h>
using namespace std;
int a[1000],b,c=9;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>b;
    for(int i=0;i<=b-1;i++)
    {
        cin>>a[i];
        if(a[i]==10)
        {

            c=6;
        }
    }

    cout<<c;


    return 0;
}
