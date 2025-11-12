#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int k=0;
    for(int i=0;i<s.size();i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            a[++k]=s[i]-'0';
        }
    }
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
