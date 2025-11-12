#include<bits/stdc++.h>
using namespace std;

//template <typename T>

void in(int &x)
{
    int f=1;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')
        c=getchar();
    if(c=='-') f=-1,c=getchar();
    for(x=0;c>='0'&&c<='9';c=getchar())
        x=x*10+(c-'0');
    x*=f;
}

struct node
{
    int a1,a2,a3;
};

int t,n;
node a[100005];

int mx(int x,int y)
{
    return (x>y)?x:y;
}

int m3(int x,int y,int z)
{
    return mx(mx(x,y),z);
}

bool cmp(node x,node y)
{
    return x.a1>y.a1;
}

int dp[205][205][205];

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    //ios::sync_with_stdio(false);
    in(t);
    for(int o=1;o<=t;o++)
    {
        in(n);
        bool okA=1;
        for(int i=1;i<=n;i++)
        {
            in(a[i].a1),in(a[i].a2),in(a[i].a3);
            if(a[i].a2!=0||a[i].a3!=0) okA=0;
        }
        if(okA)
        {
            sort(a+1,a+n+1,cmp);
            int ans=0;
            for(int i=1;i<=n/2;i++)
                ans+=a[i].a1;
            cout<<ans<<'\n';
            continue;
        }
        if(n==2)
        {
            int p1=a[1].a1+a[2].a2,p2=a[1].a1+a[2].a3;
            int p3=a[1].a2+a[2].a1,p4=a[1].a2+a[2].a3;
            int p5=a[1].a3+a[2].a1,p6=a[1].a3+a[2].a2;
            int s1=m3(p1,p2,p3),s2=m3(p4,p5,p6);
            int ans=mx(s1,s2);
            cout<<ans;
            continue;
        }
        for(int i=0;i<=n/2;i++)
        {
            for(int j=0;j<=(n/2);j++)
                for(int k=0;k<=(n/2);k++)
                {
                    //int tp=0;
                    //if((i-k-j)>n/2) continue;
                    //else tp=dp[i-1][j][k]+a[i].a3;
                    int ii=i,jj=j,kk=k;
                    if(ii==0) ii++;
                    if(jj==0) jj++;
                    if(kk==0) kk++;  
                    dp[i][j][k]=m3(dp[ii-1][j][k]+a[i+k+j].a1,dp[i][jj-1][k]+a[i+k+j].a2,dp[i][j][kk-1]+a[i+k+j].a3);
                }
        }
        
        int ans=-1;
        for(int i=0;i<=n/2;i++)
            for(int j=0;j<=n/2;j++)
            {
				int k=n-i-j;
				if(k<=n/2)
				{
					//int now=dp[i][j][k];
					ans=mx(ans,dp[i][j][k]);//,cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<'\n';
				}
					
			}  
        //cout<<'\n';        
        cout<<ans<<'\n';
        //sort(a+1,a+n+1,cmp);
        for(int i=0;i<=201;i++)
			for(int j=0;j<=201;j++)
				for(int k=0;k<=201;k++)
					dp[i][j][k]=0;
    }
    return 0;
}
