#include<bits/stdc++.h>
using namespace std;
int n;
string str;
int cnt[1005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    n=str.length();
    for(int i=0;i<n;i++)
    {
        cnt[(int)str[i]]++;
    }
    bool front=1;
    for(int i='9';i>='1';i--)
    {
        while(cnt[i]--)
        {
            cout<<(char)i;
            front=0;
        }
    }
    if(front)cout<<'0';
    else while(cnt[(int)'0']--)cout<<'0';
    return 0;
}
