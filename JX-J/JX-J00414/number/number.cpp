#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size();
    string str="";
    for(int i=0;i<l;i++)
    {
        if(isdigit(s[i]))str+=s[i];
    }
    sort(str.begin(),str.end());
    reverse(str.begin(),str.end());
    int lstr=str.size();
    for(int i=0;i<lstr;i++)
    {
        printf("%d",int(str[i]-48));
    }
    return 0;
}
