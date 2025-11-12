#include<bits/stdc++.h>
using namespace std;
int t[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
        if(isdigit(a[i]))
            t[a[i]-'0']++;
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=t[i];j++)
            cout<<i;
    }
    return 0;
}
