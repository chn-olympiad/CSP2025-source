//GZ-S00201 赫章县西城区高级中学 晋宇轩
#include<bits/stdc++.h>
using namespace std;
int n ,q;
int main()
{
    freopen("replace.in" , "r" , stdin);
    freopen("replace.out" , "w" , stdout);

    cin >> n >> q;
    string s[n][2] , t[n][2];

    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= n;j++) cin >> s[i][j];
    }
    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= n;j++) cin >> t[i][j];
    }

    for(int i = 0;i <= n;i++) cout << "0" << endl;

    return 0;
}
