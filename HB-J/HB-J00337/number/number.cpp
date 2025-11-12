#include<bits/stdc++.h>
using namespace std;
int allnum[1000005];
bool dig(char n)
{
    if(n=='0'||n=='1'||n=='2'||n=='3'||n=='4'||n=='5'||n=='6'||n=='7'||n=='8'||n=='9') return true;
    return false;
}
int cnt;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int j=0;j<s.length();j++)
    {
        if(dig(s[j]))
        {
            cnt++;
            allnum[cnt]=s[j]-'0';
        }
    }
    sort(allnum+1,allnum+cnt+1);
    for(int j=cnt;j>=1;j--) cout<<allnum[j];
    return 0;
}
