#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string s;
vector<int> a;
bool cmp(int m, int n)
{
    return m > n;
}
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        if('0' <= s[i] && s[i] <= '9')
        {
            a.push_back(s[i] - '0');
        }
    }
    sort(a.begin(), a.end(), cmp);
    if(a[0] == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }
    cout << endl;
    return 0;
}
