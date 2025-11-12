#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int a1[N],a2[N],a3[N];
int n,t,ans = 0;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin >> t;
    for(int i = 1;i <= n;i++)
    {
        cin >> a1[i] >>a2[i] >> a3[i];
        for(int j =1;j <= 3;j++)
        {
            if((a1[i] < n/2 || a2[i]  < n/2 || a3[i] < n/2) && n % 2 == 0)
            {
                ans+= i;
            }
        }
    }
    cout << ans;


    return 0;
}
