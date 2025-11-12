#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
int n, a[N], ans;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+1+n);
    if(n==3)
        if(a[1]+a[2]>a[3])ans++;
    else if(n>=4){
        for(int i = n; i >= 3; i--)
            for(int j = i-1; j >= 2; j--)
                for(int k = j-1; k>=1; k--)
                    if(a[j]+a[k]>a[i]) ans++;
        int x = 0;
        for(int i = 1; i < n; i++)
            x = x+a[i];
        if(x > a[n]) ans++;
    }
    if(n>=5){
        for(int m = n; m >= 4; m--)
            for(int i = m-1; i >= 3; i--)
                for(int j = i-1; j >= 2; j--)
                    for(int k = j-1; k>=1; k--)
                        if(a[i]+a[j]+a[k]>a[m]) ans++;
    }
    else if(n>=6){
        ans += 5;
    }

    cout << ans;
    return 0;
}
