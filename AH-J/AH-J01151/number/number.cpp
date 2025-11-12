#include<bits/stdc++.h>
using namespace std;
string s;
long long a[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long cnt=1;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' and s[i]<='9')
        {
            a[cnt]=int(s[i])-48;
            cnt++;
        }
    }
    sort(a+1,a+cnt);
    for(int i=cnt-1;i>=1;i--)cout<<a[i];
    return 0;
}
