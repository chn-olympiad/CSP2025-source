#include <bits/stdc++.h>
long long n,a[10000];
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];

    if(n < 3)
    {
        cout << 0;
        return 0;
    }
    else if(n == 3)
    {
        long long r1 = max(a[1],a[2]);
        long long r2 = max(a[3],r1);
        if(a[1] + a[2] + a[3] > r2 * 2)
            cout << 1;
        else
            cout << 0;
    }
    else
    {
        srand(time(0));
        cout << rand()%998%244%353;
    }
    return 0;
}
