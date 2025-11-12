#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FILE_IO
// #define DEBUG
// pass
// I have no idea about whether it's correct or not, but check with dp program could tell me that...
int t,n,a[100005][5],b[100005][5],cnt[5],ansj[100005],f[505][255][255];
struct Node
{
    int id,val,sortkey;
};
struct cmp
{
    bool operator () (Node a,Node b)
    {
        return a.sortkey<b.sortkey;
    }
};
priority_queue<Node,vector<Node>,cmp> q[5];
signed main()
{
    #ifdef FILE_IO
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    #define endl '\n'
    #endif // FILE_IO
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=3;i++)
        {
            cnt[i]=0;
            while(!q[i].empty())
                q[i].pop();
        }
        for(int i=1;i<=n;i++)
        {
            ansj[i]=0;
            for(int j=1;j<=3;j++)
                cin>>a[i][j],b[i][j]=0;
            for(int j=1;j<=3;j++)
                if(!b[i][1]||a[i][j]>a[i][b[i][1]])
                    b[i][1]=j;
            for(int j=1;j<=3;j++)
                if(j!=b[i][1])
                    if(!b[i][2]||a[i][j]>a[i][b[i][2]])
                    b[i][2]=j;
            for(int j=1;j<=3;j++)
                if(j!=b[i][1]&&j!=b[i][2])
                    b[i][3]=j;
            #ifdef DEBUG
            cout<<"b["<<i<<"]=";
            for(int j=1;j<=3;j++)
                cout<<b[i][j]<<" ";
            cout<<endl;
            #endif // DEBUG
        }
        if(n>500)
        {
            int ans=0;
            for(int ca=1;ca<=3;ca++)
            {
                for(int i=1;i<=n;i++)
                    if(!ansj[i])
                    {
                        int key=a[i][b[i][ca]];
                        if(ca<3)
                            key-=a[i][b[i][ca+1]];
                        q[b[i][ca]].push((Node){i,a[i][b[i][ca]],key});
                        #ifdef DEBUG
                        cout<<i<<"send requests to"<<b[i][ca]<<endl;
                        #endif // DEBUG
                    }
                for(int i=1;i<=3;i++)
                {
                    while(!q[i].empty())
                    {
                        Node now=q[i].top();
                        q[i].pop();
                        if(cnt[i]+1<=n/2)
                        {
                            ans+=now.val,ansj[now.id]=i,cnt[i]++;
                            #ifdef DEBUG
                            cout<<i<<"accept requests from"<<now.id<<"with value"<<now.val<<endl;
                            #endif // DEBUG
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
        else
        {
            for(int i=0;i<=n;i++)
                for(int j=0;j<=n/2;j++)
                    for(int k=0;k<=n/2&&k+j<=i;k++)
                        if(i-j-k<=n/2)
                            f[i][j][k]=0xc0c0c0c0c0c0c0c0ll;
            f[0][0][0]=0;
            for(int i=1;i<=n;i++)
                for(int j=0;j<=n/2;j++)
                    for(int k=0;k<=n/2&&k+j<=i;k++)
                        if(i-j-k<=n/2)
                        {
                            int l=i-j-k;
                            if(j)
                                f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
                            if(k)
                                f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
                            if(l)
                                f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
                        }
            int ans=0;
            for(int j=0;j<=n/2;j++)
                for(int k=0;k<=n/2&&k+j<=n;k++)
                    if(n-j-k<=n/2)
                        ans=max(ans,f[n][j][k]);
            cout<<ans<<endl;
        }
    }
    return 0;
}
