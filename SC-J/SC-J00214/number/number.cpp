#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
string s;
int f[N];
int fs;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for(int i = 0;i<s.size();i++)
        if(s[i] >= '0' && s[i] <= '9') 
            f[++fs] = s[i]-'0';
    sort(f+1,f+fs+1,
    [&](int x,int y)
    {
        return x > y;
    });
    for(int i = 1;i<=fs;i++)
        cout << f[i];
    cout <<"\n";
    return 0;
}