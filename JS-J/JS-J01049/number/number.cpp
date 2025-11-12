#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long LL;
const int N=1e5+8;
int n,m,a[15],l=0;
string s,ans;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]-'0'>=0&&s[i]-'0'<=9)
        {
            a[s[i]-'0']++;
        }
    }
    l=0;
    for(int i=9;i>=0;i--)
    {
        while(a[i]>0)
        {
            cout<<i;
            a[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
