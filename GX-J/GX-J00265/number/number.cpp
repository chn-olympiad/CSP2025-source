#include<bits/stdc++.h>
using namespace std;
int a[1];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=1;i<=2;i++)
    {
        cin>>a[i];
        if(a[i]==9)
        {
            cout<<"9";
        }if(a[i]==8)
        {
            cout<<"8";
        }if(a[i]==7)
        {
            cout<<"7";        
        }if(a[i]==6)
        {
            cout<<"9";
        }if(a[i]==5)
        {
            cout<<"5";
        }if(a[i]==4)
        {
            cout<<"4";
        }if(a[i]==3)
        {
            cout<<"3";
        }if(a[i]==2)
        {
            cout<<"2";
        }if(a[i]==1)
        {
            cout<<"1";
        }if(a[i]==0)
        {
            cout<<"0";
        }
    }
    return 0;
}
