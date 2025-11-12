#include <bits/stdc++.h>
using namespace std;
int fs[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> fs[i];
    }
    int a=fs[1];
    if(n==1&&m==1)
    {
        cout << 1 <<" "<<1;
    }
    else if(n==1&&m>1&&m<=10)
    {
        for(int i=1;i<=n*m-1;i++)
        {
            for(int j=1;j<=n*m-i;j++)
            {
               if(fs[j]<fs[j+1])
                {
                    swap(fs[j],fs[j+1]);
                }
            }
        }
        for(int i=1;i<=n*m;i++)
        {
            if(fs[i]==a)
            {
                cout << 1 << " "<< i;
                break;
            }
        }
    }
    return 0;
}
