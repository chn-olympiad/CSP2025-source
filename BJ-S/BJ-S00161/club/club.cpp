#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[100010][5];
queue<int> q1;
queue<int> q2;
queue<int> q3;
long long ans;
int pai[N];
bool cmp1(int x,int y)
{
    return a[x][1]<a[y][1];
}
bool cmp2(int x,int y)
{
    return a[x][2]<a[y][2];
}
bool cmp3(int x,int y)
{
    return a[x][3]<a[y][3];
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int maxn=0;
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
                if(a[i][j]>maxn)
                    maxn=j;
            }
            if(maxn==1){
                q1.push(i);
            }
            else{
                if(maxn==2)
                {
                    q2.push(i);
                }
                else{
                    q3.push(i);
                }
            }
        }
        int pa=1;
        if(q1.size()>n/2)
        {
            int len=q1.size();
            for(int i=1;i<=q1.size();i++)
            {
                int tp=q1.front();
                q1.pop();
                pai[pa]=tp;
                pa++;
            }
            sort(pai+1,pai+1+pa,cmp1);
            for(int i=1;i<=len-n/2;i++)
            {
                if(a[pai[i]][2]>a[pai[i]][3])
                {
                    q2.push(pai[i]);
                }
                else{
                    q3.push(pai[i]);
                }
            }
        }
            if(q2.size()>n/2)
            {
                int len=q2.size();
                for(int i=1;i<=len;i++)
                {
                    int tp=q2.front();
                    q2.pop();
                    pai[pa]=tp;
                    pa++;
                }
                sort(pai+1,pai+1+pa,cmp2);
                for(int i=1;i<=len-n/2;i++)
                {
                    if(a[pai[i]][1]>a[pai[i]][3])
                    {
                        q1.push(pai[i]);
                    }
                    else{
                        q3.push(pai[i]);
                    }
                }
            }

            if(q3.size()>n/2)
            {
                int len=q3.size();
                for(int i=1;i<=len;i++)
                {
                    int tp=q3.front();
                    q3.pop();
                    pai[pa]=tp;
                    pa++;
                }
                sort(pai+1,pai+1+pa,cmp3);
                for(int i=1;i<=len-n/2;i++)
                {
                    if(a[pai[i]][1]>a[pai[i]][2]&&q1.size()<n/2)
                    {
                        q1.push(pai[i]);
                    }
                    else{
                        q2.push(pai[i]);
                    }
                }
            }
        while(!q1.empty())
        {
            ans+=a[q1.front()][1];
            q1.pop();
        }
        while(!q2.empty())
        {
            ans+=a[q2.front()][2];
            q2.pop();
        }
        while(!q3.empty())
        {
            ans+=a[q3.front()][3];
            q3.pop();
        }
        cout<<ans<<"\n";
        ans=0;
        memset(pai,0,sizeof(pai));
    }
    return 0;
}
