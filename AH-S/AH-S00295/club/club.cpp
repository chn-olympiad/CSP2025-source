#include<bits/stdc++.h>
using namespace std;

struct stu
{
    int a,b,c;
};

struct stu1
{
    int sum,x,y;
};

int n,t,js[30],used[100010];
long long sum=0;
stu cl[100010];
stu1 cf[300010];
int FA=1,FB=1,cnt=0;

bool cmpA(stu x,stu y)
{
    return x.a > y.a;
}

bool cmpB(stu x,stu y)
{
    return (x.a-x.b) > (y.a-y.b);
}

bool cmpzj(stu1 x,stu1 y)
{
    return x.sum > y.sum;
}

void dfs(int k,long long sm,int yta,int ytb,int ytc)
{
    if(k == n+1)
    {
        if(yta > n/2 || ytb > n/2 || ytc > n/2) return ;
      //  if(sum == 0) sum = sm;
        else sum = max(sum,sm);
        return ;
    }
    if(yta < (n/2)) dfs(k+1,cl[k].a+sm,yta+1,ytb,ytc);
    if(ytb < (n/2)) dfs(k+1,cl[k].b+sm,yta,ytb+1,ytc);
    if(ytc < (n/2)) dfs(k+1,cl[k].c+sm,yta,ytb,ytc+1);
}

int main()
{

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cnt=0;
        sum = 0;
        cin>>n;
        FA=1,FB=1;
        for(int i = 1;i <= n;i++)
        {
            cin>>cl[i].a>>cl[i].b>>cl[i].c;
            if(cl[i].b!=0||cl[i].c!=0) FA=0;
            if(cl[i].c!=0) FB=0;
            cf[++cnt] = {cl[i].a-cl[i].b-cl[i].c,i,1};
            cf[++cnt] = {cl[i].b-cl[i].a-cl[i].c,i,2};
            cf[++cnt] = {cl[i].c-cl[i].b-cl[i].b,i,3};
        }

        if(FA)
        {
            sort(cl+1,cl+1+n,cmpA);
            for(int i = 1;i <= (n/2);i++) sum += cl[i].a;
            cout<<sum<<endl;
        }
        else if(FB)
        {
            sort(cl+1,cl+1+n,cmpB);
            for(int i = 1;i <= (n/2);i++)
            {
                sum += cl[i].a;
            }
            for(int i = (n/2+1);i <= n;i++)
            {
                sum += cl[i].b;
            }
            cout<<sum<<endl;
        }
      /*  else if(n == 2)
        {
            int ans=0;
            int tmp = 0;
            for(int i = 1;i <= 3;i++)
            {
                tmp=0;
                for(int j = 1;j <= 3;j++)
                {
                    if(i==1) tmp += cl[1].a;
                    if(i==2) tmp += cl[1].b;
                    if(i==3) tmp += cl[1].c;
                    if(j==1) tmp += cl[2].a;
                    if(j==2) tmp += cl[2].b;
                    if(j==3) tmp += cl[2].c;
                    ans= max(ans,tmp);
                    tmp=0;
                }
            }
            cout<<ans<<endl;
        }
        else if(n == 4)
        {
            int ans=0;
            int tmp = 0;
            for(int i = 1;i <= 3;i++)
            {
                tmp=0;
                for(int j = 1;j <= 3;j++)
                {
                    for(int k = 1;k <= 3;k++)
                    {
                        for(int l = 1;l <= 3;l++)
                        {
                            if(i==j==k||i==k==l||j==k==l) continue;
                            if(i==1) tmp += cl[1].a;
                            if(i==2) tmp += cl[1].b;
                            if(i==3) tmp += cl[1].c;
                            if(j==1) tmp += cl[2].a;
                            if(j==2) tmp += cl[2].b;
                            if(j==3) tmp += cl[2].c;
                            if(k==1) tmp += cl[3].a;
                            if(k==2) tmp += cl[3].b;
                            if(k==3) tmp += cl[3].c;
                            if(l==1) tmp += cl[4].a;
                            if(l==2) tmp += cl[4].b;
                            if(l==3) tmp += cl[4].c;
                            ans= max(ans,tmp);
                            tmp=0;
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }*/
        else if(n <= 17)
        {
            dfs(1,0,0,0,0);
            cout<<sum<<endl;
        }
        else
        {
            memset(used,0,sizeof(used));
            memset(js,0,sizeof(js));
            sort(cf+1,cf+1+cnt,cmpzj);
            for(int i = 1;i <= n;i++)
            {
                if(js[cf[i].y] < (n/2) && !used[cf[i].x])
                {
                    if(cf[i].y == 1)
                    {
                        sum += cl[cf[i].x].a;
                    }
                    if(cf[i].y == 2)
                    {
                        sum += cl[cf[i].x].b;
                    }
                    if(cf[i].y == 3)
                    {
                        sum += cl[cf[i].x].c;
                    }
                    js[cf[i].y]++;
                    used[cf[i].x] = 1;
                }
            }
            cout<<sum<<endl;
        }
    }

    return 0;
}
