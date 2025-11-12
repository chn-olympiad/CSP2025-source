#include<iostream>
#include<algorithm>
using namespace std;
int a[105],b[15][15];
bool cmp(int x,int y)
{

    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r=0,l=1;
    bool v=1;
    cin>>n>>m;
    int x=n*m;
    for(int i = 1;i<=x;i++)
    {
        cin>>a[i];

    }
    int y =a[1];
    sort(a+1,a+x+1,cmp);
    for(int i=1;i<=x;i++)
    {

        if(v==1&&r+1>n)
        {
            l++;
            v=0;
        }
        else if(v==0&&r-1<1)
        {
            l++;
            v=1;
        }
        else
        {
            if(v==1)
            {
                r++;
            }
            else
            {
                r--;
            }

        }
        b[l][r]=a[i];
        if(b[l][r]==y)
        {
            cout<<l<<" "<<r;
            return 0;
        }
    }
    return 0;
}
