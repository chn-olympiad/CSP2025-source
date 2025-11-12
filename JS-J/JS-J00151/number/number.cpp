#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000006];
int cmp(int x,int y)
{

    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')a[++cnt]=s[i]-48;
    }
    sort(a+1,a+cnt+1,cmp);
    string ans="";
    for(int i=1;i<=cnt;i++){
        ans+=a[i]+48;
    }
    cout<<ans;
}
