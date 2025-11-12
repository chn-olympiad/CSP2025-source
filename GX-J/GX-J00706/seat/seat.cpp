#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int siz=n*m;
    for(int i=1;i<=siz;i++)
        cin>>a[i];
    int R=a[1];
    sort(a+1,a+1+siz,cmp);
    for(int i=1;i<=siz;i++)
    {
        if(a[i]==R)
        {
            int c,r;
            if(i%n==0)
            {
                if((i/n)%2==0)
                {
                    c=i/n;r=1;
                }
                else
                {
                    c=i/n;r=n;
                }
            }
            else
            {
                if((i/n)%2==0)
                {
                    c=i/n+1;r=i%n;
                }
                else
                {
                    c=i/n+1;r=n-i%n+1;
                }
            }
            cout<<c<<" "<<r;
            break;
        }
    }
    return 0;
}
