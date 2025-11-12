#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

string s;
char a[1000005];

bool cmp(char x,char y)
{

    return x>y;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    s=" "+s;
    int cnt=0;
    for(int i=1;i<=s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            cnt++;
            a[cnt]=s[i];

        }

    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {

        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
