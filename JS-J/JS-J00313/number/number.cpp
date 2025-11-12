#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    string s;
    cin >> s;
    vector <int> a;
    for(int i = 0;i < s.size();i++)
        if(s[i] >= '0' && s[i] <= '9')
            a.push_back(s[i] - '0');
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    for(auto x : a)
        cout << x;
    cout << endl;
    return 0;
}
