#include<iostream>
#include<vector>
using namespace std;
const int maxn=100005;
int n,a[maxn][5],chs[5];
int mx(int x,int y,int z)
{
    if(x>=y&&x>=z) return x;
    else if(y>=x&&y>=z) return y;
    else return z;
}
int mx2(int x,int y)
{
    if(x>y) return x;
    else return y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    for(int ii=1;ii<=T;ii++)
    {
        cin>>n;
        vector<int> t[5];
        chs[1]=0;chs[2]=0;chs[3]=0;
        int ans=0,k=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int m=mx(a[i][1],a[i][2],a[i][3]);
            ans+=m;
            if(a[i][1]==m)
            {
                chs[1]++;
                t[1].push_back(i);
                continue;
            }
            else if(a[i][2]==m)
            {
                chs[2]++;
                t[2].push_back(i);
                continue;
            }
            else
            {
                chs[3]++;
                t[3].push_back(i);
                continue;
            }
        }
        while(chs[1]>k||chs[2]>k||chs[3]>k)
        {
            if(chs[1]>k)//1change
            {
                int bst=2147483640,bst_;
                for(int i=0;i<t[1].size();i++)
                {
                    if(t[1][i]==-1) continue;
                    if(bst>a[t[1][i]][1]-mx2(a[t[1][i]][2],a[t[1][i]][3]))
                    {
                        bst=a[t[1][i]][1]-mx2(a[t[1][i]][2],a[t[1][i]][3]);
                        bst_=i;
                    }
                }
                int i=t[1][bst_];
                t[1][bst_]=-1;
                if(a[i][2]>=a[i][3])
                {
                    t[2].push_back(i);
                    chs[1]-=1;chs[2]+=1;
                    ans=ans-a[i][1]+a[i][2];
                }
                if(a[i][3]>=a[i][2])//1 t 3
                {
                    t[3].push_back(i);
                    chs[1]-=1;chs[3]+=1;
                    ans=ans-a[i][1]+a[i][3];
                }
            }
            if(chs[2]>k)//2
            {
                int bst=2147483640,bst_;
                for(int i=0;i<t[2].size();i++)
                {
                    if(t[2][i]==-1) continue;
                    if(bst>a[t[2][i]][2]-mx2(a[t[2][i]][1],a[t[2][i]][3]))
                    {
                        bst=a[t[2][i]][2]-mx2(a[t[2][i]][1],a[t[2][i]][3]);
                        bst_=i;
                    }
                }
                int i=t[2][bst_];
                t[2][bst_]=-1;
                if(a[i][1]>=a[i][3])//2 t 1
                {
                    t[1].push_back(i);
                    chs[2]-=1;chs[1]+=1;
                    ans=ans-a[i][2]+a[i][1];
                }
                if(a[i][3]>=a[i][1])//2 t 3
                {
                    t[3].push_back(i);
                    chs[2]-=1;chs[3]+=1;
                    ans=ans-a[i][2]+a[i][3];
                }
            }
            if(chs[3]>k)//3
            {
                int bst=2147483640,bst_;
                for(int i=0;i<t[3].size();i++)
                {
                    if(t[3][i]==-1) continue;
                    if(bst>a[t[3][i]][3]-mx2(a[t[3][i]][2],a[t[3][i]][1]))
                    {
                        bst=a[t[3][i]][3]-mx2(a[t[3][i]][2],a[t[3][i]][1]);
                        bst_=i;
                    }
                }
                int i=t[3][bst_];
                t[3][bst_]=-1;
                if(a[i][1]>=a[i][2])//3 t 1
                {
                    t[1].push_back(i);
                    chs[3]-=1;chs[1]+=1;
                    ans=ans-a[i][3]+a[i][1];
                }
                if(a[i][2]>=a[i][1])//3 t 2
                {
                    t[2].push_back(i);
                    chs[3]-=1;chs[2]+=1;
                    ans=ans-a[i][3]+a[i][2];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
