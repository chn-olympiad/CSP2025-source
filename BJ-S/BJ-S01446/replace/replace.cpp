#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
#define ll long long

string s1[N],s2[N];
int n,q;

inline ll solvep(string t1,string t2)
{
    cout<<0<<'\n';
}
inline ll solve(string t1, string t2)
{
    
}

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i = 1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
    }
    for(int i = 1;i<=q;i++)
    {
        string t1,t2;
        cin>>t1>>t2;
        solvep(t1,t2);
    }

    return 0;
}
