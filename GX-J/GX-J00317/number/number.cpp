#include<bits/stdc++.h>
using namespace std;

bool cmp (int a,int b)
{
return a>b;
};
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s;
cin>>s;
int a[s.size()+1]={0},b=0;
for(int i=0;i<s.size();i++)
{
    if(s[i]<='9'&&s[i]>='0')
    {
        a[i]=s[i]-'0';
        b++;
    }
}
sort(a,a+1+s.size(),cmp);
for(int i=0;i<b;i++)
{
        cout<<a[i];
}
return 0;
}
