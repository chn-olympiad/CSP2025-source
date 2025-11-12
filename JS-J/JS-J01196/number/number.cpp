#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
map<char,int>mp;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            mp[s[i]]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=mp[i+'0'];j++)
        {
            printf("%d",i);
            cnt++;
        }
    }
    return 0;
}
