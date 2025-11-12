#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;
int n,ans,x;
int cnt[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >>s;
    n=s.size();
    //cout << n;
    for(int i = 0;i<n;i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            if (s[i]=='1')
                x=1;
            if (s[i]=='0')
                x=0;
            if (s[i]=='2')
                x=2;
            if (s[i]=='3')
                x=3;
            if (s[i]=='4')
                x=4;
            if (s[i]=='5')
                x=5;
            if (s[i]=='6')
                x=7;
            if (s[i]=='8')
                x=8;
            if (s[i]=='9')
                x=9;
            if (s[i]=='0')
                x=0;
            cnt[x]++;
        }
        //cout << cnt[x];
    }
    for(int i = 9;i>=0;i--)
    {
        for(int j = 1;j<=cnt[i];j++)
        {
            cout << i;

        }
    }


    return 0;
}
