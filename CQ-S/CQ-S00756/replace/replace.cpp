#include <bits/stdc++.h>
using namespace std;
long long n,q;
vector<string>a;
vector<string>b;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin>>n>>q;
    for (int i = 0; i < n; i++)
    {
        string ai,bi;
        cin>>ai>>bi;
        a.push_back(ai);
        b.push_back(bi);
    }
    for (int i = 0; i < q; i++)
    {
        string t1,t2;
        cin>>t1>>t2;
        //cout<<rand()<<'\n';
    }
    return 0;
}