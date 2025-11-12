#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=3)
    {
        if(n==1 || n==2)
            cout<<0;
        else if(n==3)
        {
            if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
                cout<<1;
            else
                cout<<0;
        }
    }
    else
        cout<<(n-1)*(n-2)/2;
    return 0;
}
//T4 zhi jie kai bai le
//fen shu yv ji shi : T1 100 T2 100 T3 10 T4 39
//jin nian de ti mu qian mian tai shui , hou mian you lue nan
//zhen bu zhi dao CCF zen me chu ti