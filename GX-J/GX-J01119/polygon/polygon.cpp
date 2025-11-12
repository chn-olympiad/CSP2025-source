#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m,cnt=0,max;
    cin >> n;
    cin >> m;
    for(int i = 1;i<=n;i++)
    {
        cnt++;
        if(max==n)
        {
            cout << max;
            break;
        }
    }
    return 0;
}
