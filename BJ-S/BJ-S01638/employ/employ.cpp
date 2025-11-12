#include<bits/stdc++.h>
#define MN 510
#define ll long long
using namespace std;

ll ans;
int n,m;
string st;
int num[MN];
bool bo[MN];

void fun(int x,int cnt)
{
    if(x == n)
    {
        if(cnt >= m)
            ans++;
        return ;
    }
    for(int i = 1; i <= n; i++)
    {
        if(bo[i] == false)
        {
            bo[i] = true;
            if(st[x] == '1' && x - cnt + 1 < num[i])
                    fun(x + 1,cnt + 1);
            else
                    fun(x + 1,cnt);
            bo[i] = false;
        }
    }
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> st;
    for(int i = 1; i <= n; i++)
        scanf("%d",&num[i]);
    st = " " + st;
    fun(1,0);
    cout << ans << endl;
    return 0;
}
