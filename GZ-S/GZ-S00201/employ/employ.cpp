//GZ-S00201 赫章县西城区高级中学 晋宇轩
#include<bits/stdc++.h>
using namespace std;
int n , m , ans;
int main()
{
    freopen("employ.in" , "r" , stdin);
    freopen("employ.out" , "w" , stdout);

    cin >> n >> m;
    char s[n];
    int c[n];
    for(int i=0;i < n;i++)
    {
        cin >> s[i];
        cin >> c[i];

        if(c[i+1] > c[i]) swap(c[i] , c[i+1]);
    }
    for(int i=0;i < n;i++)
    {
        if(s[i] == 1 && c[i] >= i) ans++;
    }

    cout << ans;
    /*cout << "Hello and good bye ,C++!" */

    return 0;
}
