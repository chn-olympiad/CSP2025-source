#include <bits/stdc++.h>
using namespace std;
int a[1000010],i;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,str;
    cin>>s;
    for(i=0;i<s.size();i++)
        if(s[i]>='0' && s[i]<='9')
            str+=s[i];
    for(i=0;i<str.size();i++)
        a[i]=str[i]-'0';
    sort(a-1,a+i);
    for(int j=i-1;j>=0;j--)
        cout<<a[j];
    return 0;
}
