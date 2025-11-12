#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    r=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=m;i++)
        if(i%2)
            for(int j=1;j<=n;j++)
            {
                ++cnt;
                if(a[cnt]==r)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        else
            for(int j=n;j>=1;j--)
            {
                ++cnt;
                if(a[cnt]==r)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
    return 0;
}
/*
g++ seat.cpp -o seat
seat.exe

//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
*/