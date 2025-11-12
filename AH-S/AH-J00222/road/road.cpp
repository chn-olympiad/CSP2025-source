include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int tot = 0,h = 0,q = 0,l,r;
int n;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sycn_with_stdin(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> l >> r;
    if(t < (l*n) || t > (r*n))
    {
        cin >> a[i];
        tot += a[i];
    }
    else
    {
       for(int i = 1;i <= n;i++)
       {
           if(a[i] < l) h += l - a[i];
           if(a[i] > r) q += a[i] - r;
       }
    }
    cout << max(h,q);
    return 0;
}




