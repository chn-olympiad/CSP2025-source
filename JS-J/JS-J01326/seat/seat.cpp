#include<bits/stdc++.h>
using namespace std;
long long a,b,c[105],d,e,f,i,j;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>a>>b;
    e=a*b;
    for(i=1;i<=e;i++)
    {
        cin>>c[i];
    }
    d=c[1];
    sort(c+1,c+e+1,cmp);
    for(i=1;i<=a;i++)
    {
        if(i%2==1)
        {
            for(j=1;j<=b;j++)
            {
                if(c[a*(i-1)+j]==d)
                {
                    e=i;
                    f=j;
                    break;
                }
            }
        }
        else
        {
            for(j=b;j>=1;j--)
            {
                if(c[a*(i-1)+j]==d)
                {
                    e=i;
                    f=b-j+1;
                    break;
                }
            }
        }
    }
    cout<<e<<" "<<f;
    return 0;
}
