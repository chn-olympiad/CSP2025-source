#include <bits/stdc++.h>
using namespace std;
#define int long long
int number[1000005],cnt;
bool cmp(int x,int y)
{
    return x>y;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;++i)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            number[++cnt]=s[i]-48;
        }
    }
    sort(number+1,number+cnt+1,cmp);
    for(int i=1;i<=cnt;++i)
    {
        printf("%lld",number[i]);
    }
    return 0;
}
