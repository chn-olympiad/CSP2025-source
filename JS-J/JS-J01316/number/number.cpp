#include<bits/stdc++.h>
using namespace std;
#define pq priority_queue<int,vector<int>,greater<int> >
#define ll long long
#define endl "\n"

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int cnt[10] = {};
    for(auto i : s)
    {
        //cout << "in\n";
        if('0' <= i && i <= '9')
            cnt[i-'0'] ++;
    }
    for(int i = 9;i >= 0;i --)
    {
        while(cnt[i] --) cout << i;
    }
    cout << endl;
    return 0;
}
