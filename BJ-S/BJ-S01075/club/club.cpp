//freopen记得加上
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][4];
int Ans,sz[4];
int tmp[N];
void dfs(int k,int l,int ans)
{
    if(k>n)
    {
        if(ans>Ans&&sz[1]<=(n/2)&&sz[2]<=(n/2)&&sz[3]<=(n/2))
        {
            Ans=ans;
        }
        return ;
    }
    ans+=a[k][l];
    sz[l]++;
    for(int i=1;i<=3;++i)
    {
        dfs(k+1,i,ans);
    }
    ans-=a[k][l];
    sz[l]--;
    return ;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool op=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=3;++j)
                cin>>a[i][j];
            if(a[i][3]!=0||a[i][2]!=0) op=0;
        }
        if(n<=10)
        {
            dfs(0,0,0);
            cout<<Ans<<endl;
            Ans=sz[1]=sz[2]=sz[3]=0;
        }
        else if(op==1)
        {
            for(int i=1;i<=n;++i)
            {
                tmp[i]=a[i][1];
                sort(tmp+1,tmp+n+1);
                for(int i=n;i>=n/2+1;--i)
                    Ans+=tmp[i];
                cout<<Ans<<endl;
                Ans=0;
            }
        }
        else
        {
            for(int i=1;i<=n;++i)
            {
                Ans+=max(a[i][1],max(a[i][2],a[i][3]));
            }
            cout<<Ans<<endl;
            Ans=0;
        }
    }
    return 0;
}
