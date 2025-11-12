#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 5e5 + 5;
int n,m,a[N];
int cnt,sum;
struct node
{
    int l,r;
    int xors;
}k[3*N];

struct cnotes
{
    int l,r;
    bool flag = 0;
}kt[3 * N];

void update(int st)
{
    k[st].xors = (k[st*2].xors ^ k[st*2+1].xors);
    if(st != 0) update(st/2);
}
void tree(int st,int l,int r)
{
    k[st].l = l;
    k[st].r = r;

    if(l == r)
    {
        k[st].xors = a[l];
        if(k[st].xors == m)
        {
            ++cnt;
            int p = cnt;
            kt[p].l = l;
            kt[p].r = r;
        }
        return ;
    }
    int mid = (l + r) / 2;
    tree(st*2,l,mid);
    tree(st*2+1,mid+1,r);
    update(st);
    if(k[st].xors == m)
    {
        ++cnt;
        int p = cnt;
        kt[p].l = l;
        kt[p].r = r;
    }
}

bool cmd(cnotes x,cnotes y)
{
    if(x.l != y.l) return x.l < y.l;
    else return x.r < y.r;
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];

    if(n == 1)
    {
        if(a[1] == m) cout << 1;
        else cout << 0;
        return 0;
    }

    if(n == 2)
    {
        int x = (a[1] ^ a[2]);
        if(a[1] == m && a[2] == m)
            cout << 2;
        else if(a[1] == m || a[2] == m || x == m)
            cout << 1;
        else
            cout << 0;
        return 0;
    }

    tree(1,1,n);
    sort(kt+1,kt+1+cnt,cmd);
    int lr = -1;
    for(int i = 1;i <= cnt;i++)
    {
        if(kt[i].l > lr || i == 1)
        {
            sum++;
            lr = kt[i].r;
        }
    }
    cout << sum;
    return 0;
}
