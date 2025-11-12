#include <bits/stdc++.h>
using namespace std;


int n;

struct P
{
    int a;
    int d;
    int id;
    void read(int i,int j)
    {
        cin>>a;
        d=i;
        id=j;
    }
};

bool cmp(P x,P y)
{
    if(x.a!=y.a) return x.a>y.a;
    return x.d<y.d;
}

P A[100005][4];
P AA[100005];
P AA1[100005];
P sub[100005];
int S1[100005];
int S2[100005];
int f[4][100010];
//int Sub[4][4][100010];
int cnt1=0;
int cnt[4]={0,0,0,0};
int cur1=1;
void Clear()
{
    n=0;
    cnt1=0;
    cur1=1;
    cnt[1]=0;cnt[2]=0;cnt[3]=0;cnt[0]=0;
    for(int i=0;i<=100000;i++)
    {
        S1[i]=0;
        S2[i]=0;
        sub[i].a=0;
        sub[i].d=0;
        sub[i].id=0;
        f[0][i]=0;
        f[1][i]=0;
        f[2][i]=0;
        f[3][i]=0;
        AA[i].a=0;
        AA[i].d=0;
        AA[i].id=0;
        AA1[i].a=0;
        AA1[i].d=0;
        AA1[i].id=0;
        for(int j=0;j<=3;j++)
        {
            A[i][j].a=0;
            A[i][j].d=0;
            A[i][j].id=0;
        }
    }
    return;
}
bool Cmp(P x,P y)
{
    if(x.a!=y.a) return x.a>y.a;
    return x.d<y.d;
}








int fmain()
{
    Clear();
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            A[i][j].read(j,i);
        }
        sort(A[i]+1,A[i]+n+1,cmp);
        sub[i].a=A[i][1].a-A[i][2].a;
        sub[i].id=i;
        AA[i].a=A[i][1].a;
        AA[i].d=A[i][1].d;
        AA[i].id=A[i][1].id;
    }
    //cout<<sub[2].a<<endl;
    sort(AA+1,AA+n+1,cmp);
    int ans=0;
    //for(int i=1;i<=n;i++) cout<<sub[i].a<<"&&%"<<endl;
    for(int i=1;i<=n;i++)
    {
        if(cnt[AA[i].d]>=n/2)
        {
            cnt1++;
            AA1[cnt1].d=A[AA[i].id][2].d;
            AA1[cnt1].a=A[AA[i].id][2].a;
            AA1[cnt1].id=A[AA[i].id][2].id;
            f[0][++f[0][0]]=A[AA[i].id][2].id;
            //cout<<sub[A[f[0][0]][1].id].a<<"#"<<endl;
            //Sub[A[AA[i].id][1].d][A[AA[i].id][2].d][++Sub[A[AA[i].id][1].d][A[AA[i].id][2].d][0]]=sub[A[AA[i].id][1].id].a;
        }
        else
        {
            while(AA1[cur1].a>AA[i].a)
            {
                ans+=AA1[cur1].a;
                cnt[AA1[cur1].d]++;
                cur1++;
            }
            cnt[AA[i].d]++;
            f[AA[i].d][++f[AA[i].d][0]]=AA[i].id;
            //Sub[A[AA[i].id][1].d][A[AA[i].id][2].d][++Sub[A[AA[i].id][1].d][A[AA[i].id][2].d][0]]=sub[A[AA[i].id][1].id].a;
            ans+=AA[i].a;
        }
    }
    //for(int i=1;i<=n;i++) cout<<sub[i].a<<"&&%"<<endl;
    int ans1=0;
    if(f[0][0]>0)
    {
        int z=A[A[f[0][1]][1].id][1].d;
        for(int i=1;i<=f[z][0];i++)
        {
            S1[i]=sub[f[z][i]].a;
        }
        for(int i=1;i<=f[0][0];i++)
        {
            //cout<<"*"<<f[0][i]<<endl;
            S2[i]=sub[f[0][i]].a;
        }
        sort(S2+1,S2+f[0][0]+1,greater<int>());
        sort(S1+1,S1+f[z][0]+1);
        for(int i=1;i<=min(f[0][0],f[z][0]);i++)
        {
            //cout<<S2[i]<<" "<<S1[i]<<endl;
            if(S2[i]<S1[i]) break;
            ans1+=S2[i]-S1[i];
        }
    }
    cout<<ans+ans1<<endl;
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        fmain();
    }
    return 0;
}
