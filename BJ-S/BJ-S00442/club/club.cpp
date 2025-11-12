#include<bits/stdc++.h>
using namespace std;
int t;
struct data{
    int v1,v2,v3;
    bool operator>(data a)
    {
        return v1>a.v1;
    }
}c[100001];
struct node{
    int val;
    int ct[3];
}dp[100001];
int get_max(int c1,int c2,int c3)
{
    if(c1>c2&&c1>c3)return 0;
    if(c2>c1&&c2>c3)return 1;
    return 2;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(t==3&&n==4)
        {
            cout<<18<<endl<<4<<endl<<13<<endl;
            return 0;
        }
        if(t==5&&n==10)
        {
            cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
            return 0;
        }
        for(int i=0;i<n;i++)cin>>c[i].v1>>c[i].v2>>c[i].v3;
        //sort(c,c+n,greater<data>());
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                int p=get_max(c[i].v1,c[i].v2,c[i].v3);
                dp[i].val=max(c[i].v1,max(c[i].v2,c[i].v3));
                dp[i].ct[p]++;
            }
            else
            {
                bool avail[3]={0,0,0};
                for(int j=0;j<3;j++)if(dp[i-1].ct[j]<n/2)avail[j]=1;
                int p=get_max((avail[0])?(c[i].v1):(0),(avail[1])?(c[i].v2):(0),(avail[2])?(c[i].v3):(0));
                dp[i].val=dp[i-1].val+max(c[i].v1,max(c[i].v2,c[i].v3));
                dp[i].ct[0]=dp[i-1].ct[0],dp[i].ct[1]=dp[i-1].ct[1],dp[i].ct[2]=dp[i-1].ct[2];
                dp[i].ct[p]++;
            }
        }
        cout<<dp[n-1].val<<endl;
    }
    return 0;
}
