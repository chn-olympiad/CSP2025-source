#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll a[1000011];
ll l;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            l++;
            a[l]=(s[i]-48);
        }
    }
    sort(a+1,a+l+1);
    for(int i=l;i>=1;i--)
    {

        cout<<a[i];
    }
    return 0;
}
