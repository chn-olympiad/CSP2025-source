#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],cnt=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=1;i<=s.size();i++)
    {
        char x=s[i-1];
        if(x-'0'>=0&&x-'0'<=9)
        {
            cnt++;
            a[cnt]=x-'0';
        }
    }
    sort(a+1,a+1+cnt);
    reverse(a+1,a+1+cnt);
    for(int i=1;i<=cnt;i++)
        cout<<a[i];
    return 0;
}
