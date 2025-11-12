#include<bits/stdc++.h>
using namespace std;
int n,m,s1[100005],minn=0x3f3f3f3f,minnum,c[100005];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        s1[i]=s[i]-'0';
        if(minn<c[i])
        {
        minn=c[i];
        minnum=i;
        }
    }
    cout<<minnum;
    return 0;
}

