#include <bits/stdc++.h>
using namespace std;
string s;
int a[30],t,d;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    t=s.size();
    for(int i=0;i<t;i++)
    {
        if((s[i]-48)>=0&&(s[i]-48)<=9)
        {
            a[s[i]-48]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=0;j<a[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}
