#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
bool cmp()
{
    int d,x;
    return x>d;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]>=0&&s[i]<=9)
        {
            cout<<s[i];
        }
    }
    return 0;
}


