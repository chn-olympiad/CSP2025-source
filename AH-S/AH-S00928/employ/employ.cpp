#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
string s;
int a[100001];
bool vis[100001];
void search(int d,int l)
{
    int lt=0;
    for(int j=1;j<=n;j++)
        {
            if(vis[j]!=0&&l>=a[j])
            {
                vis[j]=0;
                lt++;
            }
        }
    l+=lt;
    if(l+m>n) return;
    if(l+m==n&&d==n) cnt++;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]!=0)
        {
            vis[i]=0;
            if(s[i]==1) l++;
            search(d+1,l--);
            vis[i]=1;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    search(1,0);
    cout<<cnt;
    return 0;
}
