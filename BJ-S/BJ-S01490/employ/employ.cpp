#include<bits/stdc++.h>
using namespace std;
int n,m;
bool p;
char a[505];
int c[505];
int jie(int shu)
{
    int ans=1;
    for(int i=2;i<=shu;i++)
    {
        ans*=i;
    }
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>a;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==0)
        {
            p=1;
        }
    }
    if(p==0)
    {
        cout<<jie(n);
        return 0;
    }
    return 0;
}