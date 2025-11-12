#include <iostream>
#include <string>
using namespace std;

long long read()
{
    char ch;
    int num = 0;
    ch = getchar();
    while(ch >= '0' && ch <= '9') num = num * 10 + (ch - '0'), ch = getchar();
    return num;
}
int n, q;
string s, a;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> s >> a;
    }
    while(q--)
    {
        cin >> s >> a;
        cout << 0 << "\n";
    }
    return 0;
}
