#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n,a,b,c,sum=0;
    cin >> t;
    while (t--){
        sum=0;
        cin >> n;
        for (int i=1;i<=n;i++){
            cin >> a >> b >> c;
            int x=max(a,max(b,c));
            sum+=x;
        }
        cout << sum << '\n';
    }
    return 0;
}
