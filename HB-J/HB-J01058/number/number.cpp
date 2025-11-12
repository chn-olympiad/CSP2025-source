#include<bits/stdc++.h>
using namespace std;
const int mx=1E6+10;
string s;
int cnt[mx];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int j=0;
    for(int i=0;i<s.size();i++)
    {
        j++;
        if(s[i]>='0'&&s[i]<='9')
        {
            cnt[j]=s[i]-'0';
        }
        else j--;
    }
    sort(cnt+1,cnt+j+1);
    for(int i=j;i>=1;i--)
    {
        cout<<cnt[i];
    }
    return 0;
}
