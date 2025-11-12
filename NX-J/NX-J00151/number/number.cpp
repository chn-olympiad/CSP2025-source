#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
long long a[N],n,m=0;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(long long i=0;s[i];i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[i]=s[i]-48;
        }
        else m++;
    }
    sort(a+0,a+n+1);
    for(long long i=n;i>m;i--)
    {
        cout<<a[i];
    }
    return 0;
}
