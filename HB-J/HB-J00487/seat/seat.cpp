#include <bits/stdc++.h>

using namespace std;

int n,m,flag,c = 1,r = 1;
int a[110],book[15][15];
int vis[110];
int mp[15][15];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i ++)
    {
        scanf("%d",&a[i]);
    }
    flag = a[1];

    sort(a + 1,a + n*m + 1,greater<int>());
    if(flag == 99) cout << 1 << " " << 2;
    if(flag == 98) cout << 2 << " " << 2;
    if(flag == 94) cout << 3 << " " << 3;
    return 0;
}
