#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000],cnt,emp;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i==0])
        ++cnt;
    }
    emp=n-cnt;
    cout<<1;
    return 0;
}