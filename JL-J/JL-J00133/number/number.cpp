#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000];
bool cmp(int q,int w)
{
    return q>w;
}
int main()
{
    freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    int u=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[u]=s[i]-'0';
            u++;
        }
    }
    sort(a+1,a+1+u-1,cmp);
    for(int i=1;i<=u-1;i++)
    {
        cout<<a[i];
    }
    return 0;
}
