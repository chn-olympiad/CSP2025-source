#include<bits/stdc++.h>
#define cin fin
#define cout fout
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!
//Tabub is mine!

using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");
struct stu
{
    long long a,b,c;
    bool operator <(const stu &x) const
    {
        long long tot1=(a+b+c)/3,tot2=(x.a+x.b+x.c)/3;
        long long dt1=abs(tot1-a)+abs(tot1-b)+abs(tot1-c),dt2=abs(tot2-x.a)+abs(tot2-x.b)+abs(tot2-x.c);;
        return dt1<dt2;
    }
    bool operator >(const stu &x) const
    {
        long long tot1=(a+b+c)/3,tot2=(x.a+x.b+x.c)/3;
        long long dt1=abs(tot1-a)+abs(tot1-b)+abs(tot1-c),dt2=abs(tot2-x.a)+abs(tot2-x.b)+abs(tot2-x.c);;
        return dt1>dt2;
    }
}stud[100001],cnt[100001][4];
long long n,ans,f[100001][4];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(long long i=1;i<=n;i++)
            cin>>stud[i].a>>stud[i].b>>stud[i].c;
        sort(stud+1,stud+n+1,greater<stu>());
//        for(long long i=1;i<=n;i++)
//            cerr<<stud[i].a<<' '<<stud[i].b<<' '<<stud[i].c<<endl;
        for(long long i=1;i<=n;i++)
        {
            long long t=max({f[i-1][1],f[i-1][2],f[i-1][3]})+stud[i].a;
            if(f[i-1][1]+stud[i].a==t&&cnt[i-1][1].a<n/2)
                f[i][1]=t,cnt[i][1]={cnt[i-1][1].a+1,cnt[i-1][1].b,cnt[i-1][1].c};
            else if(f[i-1][2]+stud[i].a==t&&cnt[i-1][2].a<n/2)
                f[i][1]=t,cnt[i][1]={cnt[i-1][2].a+1,cnt[i-1][2].b,cnt[i-1][2].c};
            else if(f[i-1][3]+stud[i].a==t&&cnt[i-1][3].a<n/2)
                f[i][1]=t,cnt[i][1]={cnt[i-1][3].a+1,cnt[i-1][3].b,cnt[i-1][3].c};
            else f[i][1]=f[i-1][1],cnt[i][1]=cnt[i-1][1];
            t=max({f[i-1][1],f[i-1][2],f[i-1][3]})+stud[i].b;
            if(f[i-1][1]+stud[i].b==t&&cnt[i-1][1].b<n/2)
                f[i][2]=t,cnt[i][2]={cnt[i-1][1].a,cnt[i-1][1].b+1,cnt[i-1][1].c};
            else if(f[i-1][2]+stud[i].b==t&&cnt[i-1][2].b<n/2)
                f[i][2]=t,cnt[i][2]={cnt[i-1][2].a,cnt[i-1][2].b+1,cnt[i-1][2].c};
            else if(f[i-1][3]+stud[i].b==t&&cnt[i-1][3].b<n/2)
                f[i][2]=t,cnt[i][2]={cnt[i-1][3].a,cnt[i-1][3].b+1,cnt[i-1][3].c};
            else f[i][2]=f[i-1][2],cnt[i][2]=cnt[i-1][2];
            t=max({f[i-1][1],f[i-1][2],f[i-1][3]})+stud[i].c;
            if(f[i-1][1]+stud[i].c==t&&cnt[i-1][1].c<n/2)
                f[i][3]=t,cnt[i][3]={cnt[i-1][1].a,cnt[i-1][1].b,cnt[i-1][1].c+1};
            else if(f[i-1][2]+stud[i].c==t&&cnt[i-1][2].c<n/2)
                f[i][3]=t,cnt[i][3]={cnt[i-1][2].a,cnt[i-1][2].b,cnt[i-1][2].c=1};
            else if(f[i-1][3]+stud[i].c==t&&cnt[i-1][3].c<n/2)
                f[i][3]=t,cnt[i][3]={cnt[i-1][3].a,cnt[i-1][3].b,cnt[i-1][3].c+1};
            else f[i][3]=f[i-1][3],cnt[i][3]=cnt[i-1][3];
//           cerr<<f[i][1]<<' '<<f[i][2]<<' '<<f[i][3]<<endl;
        }
        cout<<max({f[n][1],f[n][2],f[n][3]})<<endl;
//       cerr<<endl;
        for(long long i=1;i<=n;i++)
            f[i][1]=f[i][2]=f[i][3]=0;
        for(long long i=1;i<=n;i++)
            for(long long j=1;j<=3;j++)
                cnt[i][j]={0,0,0};
    }
    fin.close();
    fout.close();
    return 0;
}
//baoli
/*#include<bits/stdc++.h>
#define cin fin
#define cout fout
using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");
int a[100001][4],n,ans;
void dfs(int now,int tot,int fir,int sec,int thr)
{
    if(now==n+1)
    {
        ans=max(ans,tot);
        return;
    }
    if(fir<n/2)
        dfs(now+1,tot+a[now][1],fir+1,sec,thr);
    if(sec<n/2)
        dfs(now+1,tot+a[now][2],fir,sec+1,thr);
    if(thr<n/2)
        dfs(now+1,tot+a[now][3],fir,sec,thr+1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                cin>>a[i][j];
        dfs(1,0,0,0,0);
        cout<<ans<<endl;
        ans=0;
    }
    fin.close();
    fout.close();
    return 0;
}
*/
