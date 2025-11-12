#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
long long ans=0;
int s1,s2,s3;
bool flag=0;
bool ok=0;
struct node
{
    int a,b,c;
}a[N];
int cmp(node a,node b)
{
    return a.a>b.a;
}
void dfs(int step,long long sum)
{

    if(step==n+1)
    {
        //cout<<"final"<<step<<" "<<sum<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
        if(s1>n/2)return ;
        if(s2>n/2)return ;
        if(s3>n/2)return ;
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=3;i++)
    {
        if(i==1)
        {
            s1++;
            if(s1>n/2)
            {
                //cout<<step<<" "<<sum<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
                s1--;
                continue;
            }
            sum+=a[step].a;
            dfs(step+1,sum);
            sum-=a[step].a;
            s1--;
        }
        else if(i==2)
        {
            s2++;
            if(s2>n/2)
            {
                //cout<<step<<" "<<sum<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
                s2--;
                continue;
            }
            sum+=a[step].b;
            dfs(step+1,sum);
            sum-=a[step].b;
            s2--;
        }
        else if(i==3)
        {
            s3++;
            if(s3>n/2)
            {
                //cout<<step<<" "<<sum<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
                s3--;
                continue;
            }
            sum+=a[step].c;
            dfs(step+1,sum);
            sum-=a[step].c;
            s3--;
        }
    }
}
void ddfs(int step,long long sum)
{

    if(step==n+1)
    {
        //cout<<"final"<<step<<" "<<sum<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
        if(s1>n/2)return ;
        if(s2>n/2)return ;
        if(s3>n/2)return ;
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=2;i++)
    {
        if(i==1)
        {
            s1++;
            if(s1>n/2)
            {
                //cout<<step<<" "<<sum<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
                s1--;
                continue;
            }
            sum+=a[step].a;
            dfs(step+1,sum);
            sum-=a[step].a;
            s1--;
        }
        else if(i==2)
        {
            s2++;
            if(s2>n/2)
            {
                //cout<<step<<" "<<sum<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
                s2--;
                continue;
            }
            sum+=a[step].b;
            dfs(step+1,sum);
            sum-=a[step].b;
            s2--;
        }
        else if(i==3)
        {
            s3++;
            if(s3>n/2)
            {
                //cout<<step<<" "<<sum<<" "<<s1<<" "<<s2<<" "<<s3<<endl;
                s3--;
                continue;
            }
            sum+=a[step].c;
            dfs(step+1,sum);
            sum-=a[step].c;
            s3--;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        s1=0,s2=0,s3=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
            if(a[i].b!=0||a[i].c!=0)flag=1;//b,c都为0
            if(a[i].c!=0)ok=1;//b，c
        }
        if(flag==0)
        {
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n;i++)
            {

                cout<<a[i].a<<" ";
            }
            cout<<endl;
            for(int i=1;i<=n/2;i++)
            {
                ans+=a[i].a;
            }
            cout<<ans<<endl;
            continue;
        }
        if(ok==0)
        {
            ddfs(1,0);
            cout<<ans<<endl;
            continue;
        }
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
/*
3
4
4 0 0
3 0 0
5 0 0
3 0 0
4
10 0 0
1 0 0
6 0 0
2 0 0
2
10 0 0
4 0 0
*/
//Ren5Jie4Di4Ling5%
