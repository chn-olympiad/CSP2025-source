#include<bits/stdc++.h>
using namespace std;
int a[500005];
struct node
{
    int sl,sr;
}b[500005];
bool cmp(node x,node y)
{
    return x.sl < y.sl;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    int cnt = 0;
    for(int l = 1;l <= n;l++)
    {
        for(int r = l;r <= n;r++)
        {
            int ans = a[l];
            for(int k = l + 1;k <= r;k++)
            {
             	ans ^= a[k];
            }
            if(ans == k)
            {
             	cnt++;
                b[cnt].sl = l;
                b[cnt].sr = r;
            }
        }
    }
    int ans = 1;
    sort(b + 1,b + cnt + 1,cmp);
    int rr = b[1].sr;
    for(int i = 1;i < cnt;i++)
    {
     	if(b[i + 1].sr < rr)
        {
            rr = b[i + 1].sr;
        }
        else if(b[i + 1].sl > rr)
        {
            ans++;
            rr = b[i + 1].sr;
        }
    }
    if(cnt == 0)
        cout << 0;
    else
        cout << ans;
    return 0;
}


