/*
CSP-J 2025 T1
Author: DFLJ
AC Time: 08:46
*/
#include<bits/stdc++.h>
using namespace std;
char ans[2000001];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    int cnt=0;
    for(auto i : s)
    {
        if(i>='0'&&i<='9')
        {
            ans[++cnt]=i;
        }
    }
    sort(ans+1,ans+cnt+1);
    for(int i=cnt; i>=1; i--)
    {
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}