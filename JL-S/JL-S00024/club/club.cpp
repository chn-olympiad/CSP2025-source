#include<bits/stdc++.h>
using namespace std;
int n,ct[5];
struct qwer
{
    int ms,ss,ls;
    int s[5];
    bool in;
}a[100010],est[5][100010];
bool te[100010];
int anss=0;
int mymax(int inA,int inB)
{
    return inA>inB? inA:inB;
}
int mymin(int inA,int inB)
{
    return inA<inB? inA:inB;
}
int USA(qwer inA,qwer inB)
{
    return inA.ms>inB.ms;
}
int CCCP(qwer inA,qwer inB)
{
    return inA.ss>inB.ss;
}
int dfs(int idx,int sa,int n1,int n2,int n3)
{
    if(idx>n)
    {
        return sa;
    }
    int te=0;
    if(n1!=n/2&&a[idx].s[1]!=a[idx].ls)
    {
        te=mymax(dfs(idx+1,sa+a[idx].s[1],n1+1,n2,n3),te);
    }
    if(n2!=n/2&&a[idx].s[2]!=a[idx].ls)
    {
        te=mymax(dfs(idx+1,sa+a[idx].s[2],n1,n2+1,n3),te);
    }
    if(n3!=n/2&&a[idx].s[3]!=a[idx].ls)
    {
        te=mymax(dfs(idx+1,sa+a[idx].s[3],n1,n2,n3+1),te);
    }
    return te;
}
void slv()
{
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].s[1]>>a[i].s[2]>>a[i].s[3];
        a[i].ms=mymax(mymax(a[i].s[1],a[i].s[2]),a[i].s[3]);
        if(a[i].ms==a[i].s[1])
            a[i].ss=mymax(a[i].s[2],a[i].s[3]);
        else if(a[i].ms==a[i].s[2])
            a[i].ss=mymax(a[i].s[1],a[i].s[3]);
        else
            a[i].ss=mymax(a[i].s[1],a[i].s[2]);
        a[i].ls=a[i].s[1]+a[i].s[2]+a[i].s[3]-a[i].ms-a[i].ss;
    }
    cout<<dfs(1,0,0,0,0)<<'\n';
    return;
}
void slvA()
{
    sort(a+1,a+1+n,USA);
    int ans=0;
    for(int i=1;i<=n/2;i++)
        ans+=a[i].ms;
    cout<<ans<<'\n';
    return;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        //memset(te,0,sizeof te);
        cin>>n;
        if(n<=30)
        {
             slv();
             continue;
        }
        bool hapA=true;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].s[1]>>a[i].s[2]>>a[i].s[3];
            if(a[i].s[2]!=0||a[i].s[3]!=0)
                hapA=false;
            a[i].ms=mymax(mymax(a[i].s[1],a[i].s[2]),a[i].s[3]);
            if(a[i].ms==a[i].s[1])
                a[i].ss=mymax(a[i].s[2],a[i].s[3]);
            else if(a[i].ms==a[i].s[2])
                a[i].ss=mymax(a[i].s[1],a[i].s[3]);
            else
                a[i].ss=mymax(a[i].s[1],a[i].s[2]);
            a[i].in=false;
        }
        if(hapA)
        {
            slvA();
            continue;
        }
        
        sort(a+1,a+1+n,USA);
        int ans=0,hn=n/2,full=114;
        for(int i=1;i<=3;i++)
            ct[i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                if(a[i].ms==a[i].s[j])
                {
                    if(ct[j]==hn)
                    {
                        full=j;
                        break;
                    }
                    a[i].in=true;
                    ct[j]++;
                    ans+=a[i].ms;
                    est[j][ct[j]]=a[i];
                }
            }
        }
        if(full!=114)
        {
            sort(est[full]+1,est[full]+ct[full]+1,CCCP);
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(!a[i].in)
                {
                    int temp=0;
                    for(int j=1;j<=ct[full];j++)
                    {
                        //if(te[j])
                        //    continue;
                        if(est[full][j].ss+a[i].ms>est[full][j].ms+a[i].ss)
                        {
                            /*
                            //te[j]=true;
                            a[i].in=true;
                            //cout<<ans<<'\n';
                            ans=ans-est[full][j].ms+est[full][j].ss+a[i].ms;
                            swap(est[full][j],a[i]);
                            //cout<<ans<<' '<<est[full][j].ms<<' '<<est[full][j].ss<<' '<<a[i].ms<<' ';
                            //cnt++;
                            break;
                            */
                            if(est[full][j].ss+a[i].ms>est[full][temp].ss+a[i].ms)
                                temp=j;
                        }
                    }
                    a[i].in=true;
                    ans=ans-est[full][temp].ms+est[full][temp].ss+a[i].ms;
                    swap(est[full][temp],a[i]);
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(!a[i].in)
                    ans+=a[i].ss;
            }
        }
        cout<<ans<<'\n';
        

    }
    return 0;
}