#include <bits/stdc++.h>

using namespace std;
vector <int> qzy;
vector<pair<int,int>> re;
int n , k ,ans;
bool tmp(pair<int,int> &a , pair<int,int> &b )
{
    if (a.second != b.second ) return a.second < b.second;
    return a.first > b.first;
}
int main()
{
    freopen("xor.in","r",stdin );
    freopen("xor.out" , "w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    qzy.resize(n+5);
    long long s;
    for (int i = 1 ; i <= n ; i++ )
    {
        int a;
        cin >> a;
        if (i == 1)
        {
            s = a;
        }
        else s ^= a;
        //cout << s << endl;
        qzy[i] = s;
    }
    if (n <= 2 && k == 0)
    {
        if (n == 1)
        {
            cout << 0 << endl;
            return 0;
        }
        if (n == 2)
        {
            cout << 1 << endl;
            return 0;
        }

    }

    for (int i = 1 ; i <= n ; i++ )
    {
        for (int j = i ; j <= n ; j++ )
        {
            if (i == 1 )
            {
                if(qzy[j] == k) re.push_back({i,j});
            }
            else
            {
                if (qzy[j] ^ qzy[i-1] == k ) re.push_back({i,j});
            }
        }
    }
    sort(re.begin(),re.end(),tmp);
    int right = 0;
    for ( int  i = 0 ; i < re.size() ; i++ )
    {
        if (re[i].first > right)
        {
            right = re[i].second;
            //cout << "l : " << re[i].first << "r : " << re[i].second << endl;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
