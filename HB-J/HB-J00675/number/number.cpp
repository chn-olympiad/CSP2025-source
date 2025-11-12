#include <bits/stdc++.h>
using namespace std;

long long cnt,a[1000001]={};
string s;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.size();i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            a[cnt+1]=s[i]-48;
            cnt++;
        }
    }
    sort(a+1,a+1+cnt);
    for(long long i=cnt;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
