#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010];
int n,m,ans;
int t=0;
int cmp(int x,int y)
{
    return x>y;
}
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int l=a.size();
    for(int i=0;i<l;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            b[t++]=a[i]-'0';
        }
    }
    sort(b,b+t,cmp);
    for(int i=0;i<t;i++)
    {
        cout<<b[i];
    }
    return 0;
}
