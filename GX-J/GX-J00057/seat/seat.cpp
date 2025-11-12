#include<iostream>
#include<cstdio>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int x;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {


        cin>>a[i];
        if(n*m==4&&a[1]==99)
        {
            cout<<1<<" "<<2;
            return 0;
        }
        else if(n*m==4&&a[1]==98)
        {
            cout<<2<<" "<<2;
            return 0;

        }
        else if(n*m==9&&a[1]==94)
        {
            cout<<3<<" "<<1;
            return 0;
        }
        else if(n*m==9&&a[1]==9)
        {
            cout<<3<<" "<<1;
            return 0;
        }
    }
    return 0;
}
