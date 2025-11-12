#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int a[501] = {};
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    unique(a + 1,a + n + 1);
    for(int i = 1;;i++)
    {
        if(a[i] == 0)
        {
            cout << i - 1;
            break;
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
