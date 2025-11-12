#include<bits/stdc++.h>
using namespace std;
string s;
int a[205];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        int k=int(s[i]-'0');
        if(k>=0&&k<=9)
        {
            a[k]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=a[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}
