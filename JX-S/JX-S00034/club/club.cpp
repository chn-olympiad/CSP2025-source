#include<bits/stdc++.h>
using namespace std;
struct gg{
    int num;
    int ct;
    int x;
};
int club1[4];
long long h=0;
bool y[300005];
int n;
int mx;
bool cmp(gg a,gg b)
{
    return a.ct>b.ct;
}
void dfs(int i,gg club[])
{

    if(i>3*n)
    {
        return ;
    }
    memset(club1,0,sizeof(club1));
    memset(y,0,sizeof(y));
    int k;
    int num1,x1;
    if(i>0)
    {
        num1=club[i].num;
        x1=club[i].x;
        k=club[i].ct;
        club[i].ct=0;
    }
    sort(club+1,club+1+3*n,cmp);
    long long d=0;
    int sum=0;
    int tot=1;
    while(sum<n)
    {

            if(y[club[tot].x]==0&&club1[club[tot].num]+1<=mx)
            {
                y[club[tot].x]=1;
                club1[club[tot].num]++;
                d+=club[tot].ct;
                sum++;
                //cout<<club[tot].ct<<' '<<club[tot].x<<endl;
            }
            tot++;
    }
    /*if(i>0)
    {
        for(int i=3*n;i>=1;i--)
        {
            if(club[i].num==num1&&club[i].x==x1)
            {
                club[i].ct=k;
            }
        }
    }*/
    h=max(h,d);
    int j=i+1;
    dfs(j,club);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {

        memset(club1,0,sizeof(club1));
        memset(y,0,sizeof(y));
        gg club[300005];
        h=0;

        cin>>n;
        mx=n/2;
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>club[ans].ct;
                club[ans].num=j;
                club[ans].x=i;
                ans++;
            }
        }
        sort(club+1,club+1+3*n,cmp);
        //cout<<mx<<endl;
        /*while(sum<n)
        {

            if(y[club[tot].x]==0&&club1[club[tot].num]+1<=mx)
            {
                y[club[tot].x]=1;
                club1[club[tot].num]++;
                h+=club[tot].ct;
                sum++;
                //cout<<club[tot].ct<<' '<<club[tot].x<<endl;
            }
            tot++;
        }*/
        dfs(0,club);
        cout<<h<<endl;
    }
    return 0;
}
