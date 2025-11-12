#include<bits/stdc++.h>
using namespace std;
char a[100001];
int a1[100010];
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            cnt++;
            a[cnt]=s[i];
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        a1[i]=a[i]-'0';
    }
    for(int j=9;j>=0;j--)
    {
        for(int i=1;i<=cnt;i++)
        {
            if(a1[i]==j)
            {
                cout<<j;
            }
        }
    }

    return 0;
}

