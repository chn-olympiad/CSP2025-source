#include<bits/stdc++.h>
using namespace std;
bool have[15];
int cnt[15];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            int k=s[i]-'0';
            have[k]=1;
            cnt[k]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        if(have[i])
        {
            while(cnt[i]--)
                cout<<i;
        }
    }
    return 0;
}
