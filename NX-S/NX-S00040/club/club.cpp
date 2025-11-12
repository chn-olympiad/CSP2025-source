#include<bits/stdc++.h>
using namespace std;
int a[100005][3];
int b[100005][3];
int n;
bool checka()
{
    for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                if(a[i][2]!= 0 || a[i][3]!= 0)
                {
                    return 0;
                }
            }
        }
    return 1;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t, maxn = 0, q, p, ans = 0;
    cin >> t;
    for(int k = 1; k <= t; k++)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= 3; j++)
            {
                cin >> a[i][j];
                b[i][j] = a[i][j];
            }
        }
        if(checka)
        {
//        for(int i = 1; i <= n; i++)
//        {
//            cout << b[i][1];
//        }
        for(int i = 1; i <= (n / 2); i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(b[j][1] > maxn)
                {
                    maxn = b[j][1];
                    q = j;
                }
            }
            ans += maxn;
            maxn = 0;
            b[q][1] = 0;
        }
        cout << ans;
        }
        else{
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= 3; j++)
                {
                    if(a[i][j] > maxn)
                    {
                        maxn = a[i][j];
                    }
                }
                ans += maxn;
                maxn = 0;
            }
            cout << ans;
        }

    }



    return 0;
}

//1 4
//1 0 0
//2 0 0
//4 0 0
//1 0 0
