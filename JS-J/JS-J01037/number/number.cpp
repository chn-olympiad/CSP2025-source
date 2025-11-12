#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    string s;cin>>s;int num[s.size()+10]={INT_MIN};int cnt=0;
    for(int i=0;i<s.size();i++)
        if(isdigit(s[i])) {cnt++;num[cnt]=s[i]-'0';}
    sort(num,num+cnt+1);
    for(int i=cnt;i>=1;i--)
        if(i!=INT_MIN) cout<<num[i];
    return 0;
}
