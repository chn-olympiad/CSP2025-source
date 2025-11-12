#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][4],ans,eq[N],cnt,s1,s2,s3;
//priority_queue<int> q1,q2,q3;
struct Node
{
    int ch,num,vl;
}q1[N],q2[N],q3[N];
bool cmp(Node x,Node y)
{
    if(x.ch!=y.ch) return x.ch>y.ch;
    return x.vl>y.vl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(eq,0,sizeof(eq));
        cin>>n;
        ans=0;
        cnt=0;
        s1=s2=s3=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
            {
                int cur=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
                q1[++s1]={cur,i,a[i][1]};
            }
            else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])
            {
                int cur=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
                q2[++s2]={cur,i,a[i][2]};
            }
            else if(a[i][3]>a[i][1]&&a[i][3]>a[i][2])
            {
                int cur=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
                q3[++s3]={cur,i,a[i][3]};
            }
            else
            {
                eq[++cnt]=i;
            }
        }
        for(int j=1;j<=cnt;j++)
        {
            int i=eq[j];
            if(a[i][1]==a[i][2]&&a[i][1]!=a[i][3])
            {
                if(s1<s2)
                {
                    q1[++s1]={0,i,a[i][1]};
                }
                else 
                {
                    q2[++s2]={0,i,a[i][2]};
                }
            }
            else if(a[i][1]==a[i][3]&&a[i][1]!=a[i][2])
            {
                if(s1<s3)
                {
                    q1[++s1]={0,i,a[i][1]};
                }
                else 
                {
                    q3[++s3]={0,i,a[i][3]};
                }
            }
            else if(a[i][3]==a[i][2]&&a[i][1]!=a[i][3])
            {
                if(s3<s2)
                {
                    q3[++s3]={0,i,a[i][3]};
                }
                else
                {
                    q2[++s2]={0,i,a[i][2]};
                }
            }
            else 
            {
                int p=min(s1,min(s2,s3));
                if(s1==p)
                {
                    q1[++s1]={0,i,a[i][1]};
                }
                else if(s2==p)
                {
                    q2[++s2]={0,i,a[i][2]};
                }
                else
                {
                    q3[++s3]={0,i,a[i][3]};
                }
            }
        }
        sort(q1+1,q1+1+s1,cmp);
        sort(q2+1,q2+1+s2,cmp);
        sort(q3+1,q3+1+s3,cmp);
        for(int i=1;i<=s1;i++) ans+=q1[i].vl;
        for(int i=1;i<=s2;i++) ans+=q2[i].vl;
        for(int i=1;i<=s3;i++) ans+=q3[i].vl;
        if(s1>n/2)
        {
            for(int i=s1;i>n/2;i--) ans-=q1[i].ch;
        }
        if(s2>n/2)
        {   
            for(int i=s2;i>n/2;i--)
            {
                ans-=q2[i].ch;
            }  
        }
        if(s3>n/2)
        {
            for(int i=s3;i>n/2;i--) ans-=q3[i].ch;
        }
        cout<<ans<<endl;
    }
    return 0;
}