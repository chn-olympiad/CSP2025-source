#include<bits/stdc++.h>
using namespace std;

int a[5005], b[5005];

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n, jsq =0;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(n < 3)
    {
        cout << 0;
    }
    if(n == 3)
    {
        int k = max(a[1], max(a[2], a[3]));
        int t = a[1] + a[2] + a[3];
        if(t > 2 * k) cout << 1;
        else cout << 0;
    }
    else{
        int t[25000000];
        sort(a + 1, a+ n+ 1);
        for(int i = 1; i <= n * n; i++)
                t[i] = 0;
        int fan = 0;
        for(int i = 1; i <= n; i++)
        {

            fan += a[i];
            for(int j = fan; j >= a[i] + 1; j--)
            {
                t[j] +=t[j - a[i]];
                t[j] = t[j] % 998244353;
            }t[a[i]]++;
        }
        b[0] = 0;
        for(int i = 1; i <= n; i++)
            b[i] = b[i - 1] + a[i];
        for(int i = 1; i <= n * n; i++)
        {
            for(int j = 1; j <= n; j++)
                if(t[i] > 2 * a[j] && 3 * a[j] >= t[i])
                {
                    for(int k = 1; k <= j; k++)
                    {
                        if(i - a[k] > 2 * a[j] || a[i] == a[j]) jsq--;
                    }
                    for(int k = 1; k <= j; k++)
                    for(int kk = 1; kk <= j; kk++)
                    {
                        int yyk = b[kk] - b[k];
                        if(i - yyk > 2 * a[j]) jsq--;
                    }
                    jsq += t[i - a[j]];
                    jsq = jsq % 998244353;
                }
        }
        cout << jsq;
    }
}
