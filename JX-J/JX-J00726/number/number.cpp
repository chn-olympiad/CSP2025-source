#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
long long len = 1;
long long i;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(i=0;i<=s.length()-1;i++)
    {
        if(((s[i] - '0') <= 9) && ((s[i] - '0') >= 0))
        {
            a[len] = s[i] - '0';
            len++;
        }
    }
    sort(a+1,a+len);
    if(a[len-1] == 0)
    {
        cout<<"0"<<endl;
    }
    for(i=len-1;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
