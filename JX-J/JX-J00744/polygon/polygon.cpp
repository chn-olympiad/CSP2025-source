#include<iostream>
#include<fstream>
using namespace std;
int n;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int mxn=0,sm=0;
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        sm+=temp;
        if(mxn<temp)
        {
            mxn=temp;
        }
    }
    if(sm<=2*mxn||n<3)
    {
        cout<<0;
        return 0;
    }
    else
    {
        cout<<1;
        return 0;
    }
}
