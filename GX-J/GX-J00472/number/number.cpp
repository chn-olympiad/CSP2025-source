#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y)
{
    return x>y;
}
int zhong[1000000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,shu;
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0' ||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
        {
            shu+=s[i];
        }
    }
    int cnt=shu.size();
    for(int i=0;i<shu.size();i++)
    {
        if(shu[i]=='0') zhong[i]=0;
        else if(shu[i]=='1') zhong[i]=1;
        else if(shu[i]=='2') zhong[i]=2;
        else if(shu[i]=='3') zhong[i]=3;
        else if(shu[i]=='4') zhong[i]=4;
        else if(shu[i]=='5') zhong[i]=5;
        else if(shu[i]=='6') zhong[i]=6;
        else if(shu[i]=='7') zhong[i]=7;
        else if(shu[i]=='8') zhong[i]=8;
        else if(shu[i]=='9') zhong[i]=9;
    }
    sort(zhong,zhong+cnt,cmp);
    for(int i=0;i<cnt;i++)
    {
        cout << zhong[i];
    }
    return 0;
}
