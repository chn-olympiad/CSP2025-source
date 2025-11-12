#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
int a[1000000];
string s;
cin>>s;

int e=0;
for(int i=0;i<s.size();i++)
{
if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
{
    a[e]=s[i]-'0';
    e++;
}
}
sort(a,a+s.size()+1,cmp);
for(int i=0;i<e;i++)
{

    cout<<a[i];
}
return 0;}
