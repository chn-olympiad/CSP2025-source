#include <bits/stdc++.h>
using namespace std;
long long T,n;
long long A[100005],B[100005],C[100005],mx=-1;
void dfs(long long now,long long num,long long a,long long b,long long c)
{
    if(now==n+1)
    {
        mx=max(mx,num);
        return ;
    }
    if(a<(n/2)) dfs(now+1,num+A[now],a+1,b,c);
    if(b<(n/2)) dfs(now+1,num+B[now],a,b+1,c);
    if(c<(n/2)) dfs(now+1,num+C[now],a,b,c+1);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>A[i]>>B[i]>>C[i];
        dfs(0,0,0,0,0);
        cout<<mx<<endl;
        mx=-1;
    }
    /*
    #include <bits/stdc++.h>
using namespace std;
long long n,T,ans=0;
struct P{
    long long s1,s2,s3,mx,mn;
    bool pd=0;
};
long long cnt[4];
void work()
{
    ans=0;
    P student[100005];
    cin>>n;
    long long MX=n/2;
    for(int i=1;i<=n;i++)
    {
        cin>>student[i].s1>>student[i].s2>>student[i].s3;
        if(student[i].s1==max(student[i].s1,max(student[i].s2,student[i].s3))) student[i].mx=1;
        if(student[i].s2==max(student[i].s1,max(student[i].s2,student[i].s3))) student[i].mx=2;
        if(student[i].s3==max(student[i].s1,max(student[i].s2,student[i].s3))) student[i].mx=3;
        if(student[i].s1==min(student[i].s1,min(student[i].s2,student[i].s3))) student[i].mn=1;
        if(student[i].s2==min(student[i].s1,min(student[i].s2,student[i].s3))) student[i].mn=2;
        if(student[i].s3==min(student[i].s1,min(student[i].s2,student[i].s3))) student[i].mn=3;
    }
    cnt[1]=0;
    cnt[2]=0;
    cnt[3]=0;
    for(int j=1;j<=n;j++)
    {
        if(student[j].mx==1 && cnt[1]<MX && student[j].pd==0)
        {
            student[j].pd=1;
            cnt[1]++;
            ans+=student[j].s1;
            cout<<j<<" "<<"Ss"<<student[j].s1<<"s1"<<endl;
        }
        if(student[j].mx==2 && cnt[2]<MX && student[j].pd==0)
        {
            student[j].pd=1;
            cnt[2]++;
            ans+=student[j].s2;
            cout<<j<<" "<<"Ss"<<student[j].s2<<"s2"<<endl;
        }
        if(student[j].mx==3 && cnt[3]<MX && student[j].pd==0)
        {
            student[j].pd=1;
            cnt[3]++;
            ans+=student[j].s3;
            cout<<j<<" "<<"Ss"<<student[j].s3<<"s3"<<endl;
        }
    }
    for(int j=1;j<=n;j++)
    {
        if(student[j].pd==1) break;
        if(student[j].mx==student[j].s1)
        {
            if(student[j].mn==student[j].s2)
            {
                if(cnt[3]<MX)
                {
                    cout<<j<<" "<<"S"<<student[j].pd<<" "<<student[j].s3<<"s3"<<endl;
                    student[j].pd=1;
                    cnt[3]++;
                    ans+=student[j].s3;
                }
                else
                {
                    if(cnt[2]<MX)
                    {
                        student[j].pd=1;
                        cnt[2]++;
                        ans+=student[j].s2;
                        cout<<j<<" "<<"S"<<student[j].s2<<"s2"<<endl;
                    }
                }
            }
            if(student[j].mn==student[j].s3)
            {
                if(cnt[2]<MX)
                {
                    student[j].pd=1;
                    cnt[2]++;
                    ans+=student[j].s2;
                    cout<<j<<" "<<"S"<<student[j].s2<<"s2"<<endl;
                }
                else
                {
                    if(cnt[3]<MX)
                    {
                        student[j].pd=1;
                        cnt[3]++;
                        ans+=student[j].s3;
                        cout<<j<<" "<<"S"<<student[j].s3<<"s3"<<endl;
                    }
                }
            }
        }
        else if(student[j].mx==student[j].s2)
        {
            if(student[j].mn==student[j].s1)
            {
                if(cnt[3]<MX)
                {
                    student[j].pd=1;
                    cnt[3]++;
                    ans+=student[j].s3;
                    cout<<j<<" "<<"S"<<student[j].s3<<"s3"<<endl;
                }
                else
                {
                    if(cnt[1]<MX)
                    {
                        student[j].pd=1;
                        cnt[1]++;
                        ans+=student[j].s1;
                        cout<<j<<" "<<"S"<<student[j].s1<<"s1"<<endl;
                    }
                }
            if(student[j].mn==student[j].s3)
            {
                if(cnt[1]<MX)
                {
                    student[j].pd=1;
                    cnt[1]++;
                    ans+=student[j].s1;
                    cout<<j<<" "<<"S"<<student[j].s1<<"s1"<<endl;
                }
                else
                {
                    if(cnt[3]<MX)
                    {
                        student[j].pd=1;
                        cnt[3]++;
                        ans+=student[j].s3;
                        cout<<j<<" "<<"S"<<student[j].s3<<"s3"<<endl;
                    }
                }
            }
        }
        else if(student[j].mx==student[j].s3)
        {
            if(student[j].mn==student[j].s1)
            {
                if(cnt[2]<MX)
                {
                    student[j].pd=1;
                    cnt[2]++;
                    ans+=student[j].s2;
                    cout<<j<<" "<<"S"<<student[j].s2<<"s2"<<endl;
                }
                else
                {
                    if(cnt[1]<MX)
                    {
                        student[j].pd=1;
                        cnt[1]++;
                        ans+=student[j].s1;
                        cout<<j<<" "<<"S"<<student[j].s1<<"s1"<<endl;
                    }
                }
            }
            if(student[j].mn==student[j].s2)
            {
                if(cnt[1]<MX)
                {
                    student[j].pd=1;
                    cnt[1]++;
                    ans+=student[j].s1;
                    cout<<j<<" "<<"S"<<student[j].s1<<"s1"<<endl;
                }
                else
                {
                    if(cnt[2]<MX)
                    {
                        student[j].pd=1;
                        cnt[2]++;
                        ans+=student[j].s2;
                        cout<<j<<" "<<"S"<<student[j].s2<<"s2"<<endl;
                    }
                }
            }
        }
    }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++) work();
}
*/
}
