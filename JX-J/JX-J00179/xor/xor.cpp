#include<bits/stdc++.h>
using namespace std;
long long a[500001];
long long q[500001];
struct node
{
    int l,r;
};
node ans[500001];
bool cmp(node x,node y)
{
    if(x.r == y.r)return x.l>y.l;
    return x.r<y.r;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin >> n >> k;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
        q[i] = q[i-1]^a[i];
    }
    int cnt = 0;
    for(int i = 1;i<n;i++)
    {
        for(int j = i;j<=n;j++)
        {
            if((q[j]^q[i-1]) == k)
            {
                cnt++;
                ans[cnt].l = i;
                ans[cnt].r = j;
                break;
            }
        }
    }
    sort(ans+1,ans+cnt+1,cmp);
    int dqr = 0;
    int sum = 0;
    for(int i = 1;i<=cnt;i++)
    {
       if(dqr<ans[i].l)
       {
           dqr = ans[i].r;
           sum++;
       }
    }
    cout << sum;
    return 0;
}
