#include<iostream>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,ans = 0;
    int an[n];
    cin >> t;
    for(int i = 0;i <= t;i++)
    {
        cin >> n;
        int a[2] = {};
        for(int j = 0;j <= n;j++)
        {
            cin >> a[0] >> a[1]>>a[2];
            ans += max(a[0],a[1],a[2]);
        }
        cout << ans<<endl;

    }


    return 0;
}