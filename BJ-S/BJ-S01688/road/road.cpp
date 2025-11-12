#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k,a,b,c;
    long long sum=0;
    cin >> n >> m >> k;
    for (int i=1;i<=m;i++){
        cin >> a >> b >> c;
        sum+=c;
    }
    cout << sum;
    return 0;
}
