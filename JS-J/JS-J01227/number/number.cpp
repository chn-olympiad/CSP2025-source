#include<bits/stdc++.h>
using namespace std;
string s;
int f[1000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size(),m=0;
    for(int i=0;i<=n-1;i++)
    {
        if(isdigit(s[i]))
        {
            m++;
            f[m]=s[i]-'0';
        }
    }
    sort(f+1,f+m+1);
    reverse(f+1,f+m+1);
    for(int i=1;i<=m;i++)
    {
        cout<<f[i];
    }
    return 0;
}
