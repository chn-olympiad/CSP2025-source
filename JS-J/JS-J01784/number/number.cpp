#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int j=0;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            a[++j]=s[i]-'0';
        }
    }
    sort(a+1,a+j+1);
    for(int i=j;i>=1;i--)
    {

        cout<<a[i];
    }
    return 0;
}
/*
*/
