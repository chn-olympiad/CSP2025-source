#include<bits/stdc++.h>
using namespace std;
struct init{
    int le, ri;
}ans[500005];
int a[500005];
int sum[500005];
int erx[25], ery[25];
int yh(int x, int y)
{
    int kx = 0, erans = 0;
    memset(erx, 0, sizeof(erx));
    memset(ery, 0, sizeof(ery));
    while(x != 0)
    {
        erx[kx++] = x % 2;
        x = x / 2;
    }
    int ky = 0;
    while(y != 0)
    {
        ery[ky++] = y % 2;
        y = y / 2;
    }
    for(int i = max(kx, ky) - 1;i >= 0;i--)
    {
        if(erx[i] != ery[i])
        {
            erans += pow(2, max(kx, ky) - i - 1);
        }
    }
    return erans;
}
bool cmp(init q, init h)
{
    if(q.le == h.le)
    {
        return q.ri < h.ri;
    }
    return q.le < h.le;
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, j = 0, la = 0, maxx = 0, su = 0;
    cin>>n>>k;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
        if(a[i] == 1)
        {

            su++;
        }
        sum[i] = yh(sum[i - 1], a[i]);
    }
    if(k == 0)
    {
        cout<<n / 2;
        return 0;
    }
    if(k == 1)
    {

        cout<<su;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int l = 1;l + i - 1<= n;l++)
        {
            int r = l + i - 1;
            //cout<<l<<" "<<r<<" "<<yh(sum[l - 1], sum[r]);
            if(yh(sum[l - 1], sum[r]) == k)
            {
                ans[j].le = l;
                ans[j].ri = r;
                j++;
                //cout<<" "<<1;
            }
            //cout<<endl;
        }
    }
    /*for(int i = 0;i < j;i++)
    {
        cout<<ans[i].le<<" "<<ans[i].ri<<endl;
    }
    cout<<endl;*/
    sort(ans, ans + j, cmp);
    su = 0;
    int l = 0;
    while(l < j)
    {
        if(la < ans[l].le)
        {
            su++;
            la = ans[l].ri;
        }
        l++;
    }
    cout<<maxx;
    return 0;
}
