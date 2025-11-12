#include<bits/stdc++.h>
using namespace std;
int a[1005];
string s1;
int iii(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int j = 0;
    getline(cin,s1);
    for(int i = 0;i<s1.length();i++)
    {
        if(s1[i]-'0'>=49&&s1[i]-'0'<=74)
        {
            continue;
        }
            a[j]=s1[i]-'0';
            j++;
    }
    sort(a,a+j-1,iii);
    for(int i = 0;i<j;i++)
    {
        cout<<a[i];
    }
    return 0;
}
