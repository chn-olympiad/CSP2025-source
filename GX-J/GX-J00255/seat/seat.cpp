/*
lao tian bao you
neng ac
zhen de qiu qiu le
zhe ti bu a wo ma hui hen nan shou de
wo ye shi
suo yi xi wang neng ac
 . .
> - <
ru guo neng ac yi er ti wo jiu te bie kai xin
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[107];
// int ans[17][17];
int idx=1;
int ansx=1,ansy=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
        cin >> a[i];
    int target=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    /*
        3 3
        target = 94
        before sort 94 100 37 29 80 96 92 93 95
        after sort 100 96 95 94 93 92 80
        37 29
        wei zhi
        100
        96
        95 94
        ac
    */
    for(int i=1;i<=n*m;i++)
    {
        if(i==idx*n+1)
        {
            idx++;
            ansy++;
            if(idx%2==0)
                ansx=n;
            else
                ansx=1;
        }

        if(a[i]==target)
        {
            break;
        }
        if(idx%2==1) ansx++;
        else
            ansx--;

    }
    cout << ansy <<' ' << ansx;
    return 0;
}
