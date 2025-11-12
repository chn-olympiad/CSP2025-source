#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int nums[1000005],id;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int len=s.size();
    s=' '+s;
    for(int i=1;i<=len;i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            nums[++id]=int(s[i]-'0');
        }
    }
    sort(nums+1,nums+id+1,cmp);
    for(int i=1;i<=id;i++)
    {
        cout<<nums[i];
    }
    return 0;
}
