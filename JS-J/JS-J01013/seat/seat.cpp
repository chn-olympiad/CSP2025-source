#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[15][15],x,xn=1,yn=1;
    int g[105],gr;
    memset(g,0,sizeof(g));
    cin >> n >> m;
    cin >> gr;
    for(int i =2;i<=n*m;i++)
    {
            cin >> x;
            g[x]++;
    }

    for(int i = 100;i>=1;i--)
    {
        for(int j = 1;j<=g[i];j++)
        {
            if(xn%2==1)
            {
                yn++;
            }
            if(yn>m)
            {
                yn-=1;
                xn+=1;
                continue;
            }
            if(xn%2==0)
            {
                yn--;
            }
            if(yn<=0)
            {
                yn+=1;
                xn+=1;
                continue;
            }
        }
        if(i==gr)
        {
            cout << xn << " " << yn;
            break;
        }
    }
    return 0;
}
