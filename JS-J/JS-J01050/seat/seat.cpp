#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n,m,mb;
bool cmp(int a,int b) {return a > b;}
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    vector<int>a;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)
    {
        int k;cin >> k;
        a.push_back(k);
    }
    mb = a[0];
    sort(a.begin(),a.end(),cmp);
    int c,r;
    for(int i = 0;i < a.size();i++)
    {
        if(a[i] == mb)
        {
            mb = i + 1;
            break;
        }
    }
    c = (mb - 1) / n + 1; r = (mb - 1) % n + 1;
    if(c % 2 == 0) r = n - r + 1;
    cout << c << ' ' << r << '\n';
    return 0;
}