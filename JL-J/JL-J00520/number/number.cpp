#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
const int N=1e6+10;
int j=1;
int a[N];
bool cmp(int a,int b)
{
    return a>b;
}
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[j++]=s[i]-'0';
        }
    }
    sort(a+1,a+1+j,cmp);
    for(int i=1;i<j;i++)
        cout<<a[i];
    cout<<'\n';
    return 0;
}
