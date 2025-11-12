#include<bits/stdc++.h>
using namespace std;
//包含小写英文字母及数字 可以选相同的数字
//正整数的最大值
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    if(s.size()==1)
    {
        cout<<s;
        return 0;
    }
    else
    {
        sort(s.begin(),s.end());
        for(int i=s.size()-1;i>=0;i--)
        {
            if((s[i]>='1' && s[i]<='9')|| s[i]=='0')
            {
                cout<<s[i];
            }
        }
    }


    return 0;
}