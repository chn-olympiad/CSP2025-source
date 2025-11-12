#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005],temp,ans_l[50005],ans_r[50005],sum,ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if (a[i] == k)
        {
            ans++;
            ans_l[ans] = i;
            ans_r[ans] = i;
        }
        temp = a[i];
        for(int j = i+1; j <= n; j++)
        {
            temp = temp^a[j];
            if(temp == k)
            {
                ans++;
                ans_l[ans] = i;
                ans_r[ans] = j;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
