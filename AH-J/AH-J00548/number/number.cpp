#include<bits/stdc++.h>
using namespace std;
string s;
int n;
int a[1000005],ac;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    n=s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0' && s[i]<='9')
            a[++ac]=s[i]-'0';
    }
    sort(a+1,a+ac+1);
    for(int i=ac;i>=1;i--)
        cout<<a[i];
    return 0;
}
