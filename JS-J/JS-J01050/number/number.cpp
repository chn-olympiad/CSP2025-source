#include<bits/stdc++.h>
using namespace std;
#define int long long int
bool cmp(int a,int b) {return a > b;}
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    string s;
    vector<int>num;
    cin >> s;
    for(auto i : s)
    {
        if(i >= '0' && i <= '9')
        {
            num.push_back((i - '0'));
        }
    }
    sort(num.begin(),num.end(),cmp);
    for(auto i : num)
    {
        cout << i;
    }
    cout << '\n';
    return 0;
}