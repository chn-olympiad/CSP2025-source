#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("clud.in","r",stdin);
    freopen("clud.out","w",stdout);

    long long int t = 0;
    scanf("%lld",&t);
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        long long int r[4] = {0,0,0,0};
        long long int p[4] = {0,0,0,0};
        long long int a[n],b[n],c[n];
        for(long long int i = 1;i <= n;i++){
            cin >> a[i] >> b[i] >> c[i];
        }
        for(long long int i = 0;i < n;i++){
            for(long long int j = 0;j < i;j++){
                if(a[j] < a[j + 1] || b[j] < b[j + 1] || c[j] < c[j + 1]){
                    swap(a[i],a[j]);
                    swap(b[i],b[j]);
                    swap(c[i],c[j]);
                }
            }
        }

        for(long long int i = 1;i <= n;i++){
            long long int e[4] = {0,a[i],b[i],c[i]};
            int l = 0;
            if(a[i] > b[i] && a[i] > c[i])
            {
                l = 1;
            }
            else
            {
                if(b[i] > a[i] && b[i] > c[i])
                {
                    l = 2;
                }
                else
                {
                    if(c[i] > a[i] && c[i] > b[i])
                    {
                        l = 3;
                    }
                }
            }
            if(r[l] < n / 2)
            {
                r[l]++;
                p[l] += e[l];
            }
            else
            {
                for(int k = 1;k <= 3;k++){
                    if(r[k] < n / 2){
                        r[k]++;
                        p[k] += e[k];
                        break;
                    }
                }
            }
        }
        cout << p[1] + p[2] + p[3] << '\n';
    }

    return 0;
}
