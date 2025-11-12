#include <bits/stdc++.h>
using namespace std;
struct qw{
    long long w;
    long long e;
    long long r;
}s[100000];
bool qwe(qw a,qw b,qw c)
{
    if(a.w!=b.w&&a.w!=c.w&&b.w!=c.w)
    return a.w>b.w>c.w;
    else if()
}
int main()
{
    int q;
    int n;
    cin>>q>>;
    for(int i=1;i<=q;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>s[j].w>>s[j].e>>s[j].r;
            sort(s+1,s+n+1,qwe);
        }
    }
}