#include<bits/stdc++.h>
using namespace std;
int i,n,a[105];
string s;
bool cmp(int x,int y)
{
    if(x>y)return 1;
    else return 0;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(i=0;i<=s.size()-1;i++)
        if(s[i]>='0'&&s[i]<='9')
            a[++n]=s[i]-48;
    sort(a+1,a+1+n,cmp);
    for(i=1;i<=n;i++)
        cout<<a[i];
    return 0;
}
