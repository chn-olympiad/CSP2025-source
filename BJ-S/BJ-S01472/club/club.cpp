#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
}a[100007];
    int n,j,k,l,cnt,maxx;
void dfs(int u)
{
    if(u==n+1)
    {

        maxx=max(maxx,cnt);
        return;
    }
    if(j<n/2)
    {
        cnt+=a[u].x;
        j++;
        dfs(u+1);
        j--;
        cnt-=a[u].x;
    }
    if(k<n/2)
    {
        cnt+=a[u].y;
        k++;
        dfs(u+1);
        k--;
        cnt-=a[u].y;
    }
    if(l<n/2)
    {
        cnt+=a[u].z;
        l++;
        dfs(u+1);
        l--;
        cnt-=a[u].z;
    }
}
bool cmp(node xx,node yx)
{

    return xx.x>yx.x;
}
int main()
{
   freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int cnts=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        if(n>201)
        {
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=n/2;i++)
            {
                cnts+=a[i].x;
            }
            cout<<cnts<<endl;
            continue;
        }
        j=k=l=cnt=0;
        maxx=-2e9;
        dfs(1);
        cout<<maxx<<endl;
    }

    return 0;
}
