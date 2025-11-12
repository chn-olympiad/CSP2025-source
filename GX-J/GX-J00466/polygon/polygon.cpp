#include <bits/stdc++.h>
using namespace std;
int n,m,ai,r,cnt=1;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n >> m;
    cin >> r;
    for(int i = 1;i<n*m;i++)
    {
        cin >> ai;
        if(ai>r)
        {
            cnt++;
        }
    }
    int l = (cnt+n-1)/n;
    cout << l << ' ';
    if(l%2==1)
    {
        cout << cnt+n-l*n;
    }
    else
    {
        cout << l*n-cnt+1 ;
    }
    return 0;
}
