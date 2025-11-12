#include<bits/stdc++.h>
using namespace std;
int a[10000005],num=0;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
       if(('0'<=s[i])&&(s[i]<='9'))
       {
           num++;
           a[num]=int(s[i]-48);
       }
    }
    sort(a+1,a+num+1);
    for(int j=num;j>0;j--)
    {
       cout<<a[j];
    }
}
