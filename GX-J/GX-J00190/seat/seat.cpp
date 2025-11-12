#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
bool u(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int x=a[1];
    sort(a+1,a+n*m+1,u);
    int n1=1,m1=1,p=1;
    for(int i=1;i<=n*m;i++)
    {
        if(a[p]==x)
        {
            cout<<m1<<' '<<n1;
            return 0;
        }
        else{
            if(m1%2==1)
            {
                if(n==n1)
                {
                    m1++;
                }
                else{
                    n1++;
                }
            }
            else{
                if(n1==1)
                {
                    m1++;
                }
                else{
                    n1--;
                }
            }
            p++;
        }
    }
    return 0;
}
