#include<bits/stdc++.h>
using namespace std;

const int N=1000010;

string s;
int num[N],cnt=0;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if('0'<=s[i]&&s[i]<='9')
            num[++cnt]=s[i]-'0';
    }

    sort(num+1,num+cnt+1);

    for(int i=cnt;i>=1;i--)
        cout<<num[i];

    return 0;
}
