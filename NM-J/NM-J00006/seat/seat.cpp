#include <bits/stdc++.h>
using namespace std;
int n, m, a[144], s[12][12];
bool cmp(int x, int y)
{
    return x > y;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++){
        cin >> a[i];
    }
    int R = a[1], pos = 1;
    sort(a + 1, a + n * m + 1, cmp);
    for (int i = 1;i <= n;i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 1;j <= m;j++)
            {
                s[j][i] = a[pos++];
            }
        }
        else
        {
            for (int j = m;j >= 1;j--)
            {
                s[j][i] = a[pos++];
            }
        }
    }
    /*for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++){
            cout<<s[i][j]<<" ";
        }
        cout << "\n";
    }*/
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            if (s[j][i] == R){
                cout << i << " "<< j;
                return 0;
            }
}
