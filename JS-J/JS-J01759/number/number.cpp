#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int j=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            a[j++]=s[i]-'0';
        }
    }
    sort(a,a+j,greater<int>());
    for(int i=0;i<j;i++)
    {
        cout<<a[i];
    }
    return 0;
}
