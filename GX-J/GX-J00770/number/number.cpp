#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string s;
int a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    int l=s.size(),j=0;
    for(int i=0;i<l;i++)
        if(s[i]>='0'&&s[i]<='9')
            j++,a[j]=s[i]-'0';
    sort(a+1,a+j+1);
    for(;j>0;j--)
        cout<<a[j];
    return 0;
}
