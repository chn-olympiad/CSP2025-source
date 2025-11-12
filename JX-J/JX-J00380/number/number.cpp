#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
cin>>a;
int s[10]={0};
for(int i=0;i<a.length();i++)
{
    if(a[i]>='0'&&a[i]<='9')
    {
        int n=a[i]-'0';
        s[n]++;
    }
}
for(int i=9;i>=0;i--)
{
  for(int j=1;j<=s[i];j++)
    cout<<i;
}
return 0;
}
