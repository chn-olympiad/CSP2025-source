#include<bits/stdc++.h>
using namespace std;
long long a,c[100000]={0},j=0;
char d[100000];
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string b,aa;
cin>>b;
for(int i=0;i<b.size();i++)
{
    if(b[i]>='0'&&b[i]<='9'){
     c[i]=b[i]-'0';aa+=b[i];
     j++;
    }
}
for(int i=0;i<aa.size();i++)
{
    c[i]=aa[i]-'0';
}
sort(c,c+1+j);
for(int i=aa.size();i>=0;i--)
{
    cout<<c[i];
}
return 0;
}
