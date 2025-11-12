#include<bits/stdc++.h>
#define N 1000005
using namespace std;
string s;
int a[N],l,m;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.length();
    for(int i=0;i<l;i++)
        if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
            a[++m]=s[i]-'0';
    sort(a+1,a+m+1,greater<int>());
    for(int i=1;i<=m;i++)
        cout<<a[i];
    return 0;
}
