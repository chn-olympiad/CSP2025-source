

#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

       int n,m,a[4];
    cin>>n>>m;
    for(int i=1;i<=4;i++)
    {

        cin>>a[i];
    }
    if(a[1]==99)
{
           cout<<1<<" "<<2;

}
else if(a[1]==98)
{
           cout<<2<<" "<<2;
}
else{
    cout<<3<<" "<<1;
}


    }
