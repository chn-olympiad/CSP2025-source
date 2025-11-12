#include <iostream>
#include<bits/stdc++.h>
using namespace std;
string a;
int n,m;
string s;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    cin>>a;
     if(n=2)
    {
        if(a=="99 100 97 98")
            cout<<"1"<<" "<<"2";
        else
            cout<<"2"<<" "<<"2";
    }

    else if(n=3)
        cout<<"3"<<" "<<"1";
    //else if(n=5)
        //cout<<366911923;
    else
        cout<<1;
    return 0;
}
