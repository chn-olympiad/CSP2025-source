#include<bits/stdc++.h>
using namespace std;
int n, t, a[100010][4], ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        ans = 0;
        cin >> n;
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        for(int j=1;j<=n;j++)
        {
            ans += max(max(a[i][1],a[i][2]),a[i][3]);
        }
        cout << ans << endl;
    }
	return 0;
}
