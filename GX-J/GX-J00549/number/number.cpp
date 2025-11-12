#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool px(long long x,long long y)
{
    return x>y;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[1000100]={0},way=0;
    for(int i=0;i<s.size();i++)
    {
        int num=s[i]-'0';
        if(num>=0&&num<10)
        {
            a[way]=num;
            way++;
        }
    }
    sort(a+0,a+way,px);
    for(int i=0;i<way;i++)
    {
        cout<<a[i];
    }
    return 0;
}
