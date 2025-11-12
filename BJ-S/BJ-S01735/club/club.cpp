#inculde<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
int a[N][4],m,n,r_1,r_2,r_3,cnt,z,x,y;
int main()
{
    freopen("club.in","r"stdin);
    freopen("club.out","w"stdout);
    cin>>m;
    for(int k=0;k<=m;k++)
    {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(j==1)
            {
                if(a[i][j]>=a[i][j+1]||a[i][j]>=a[i][j+2])
                {
                    r_1+=1;
                }
            }
            if(j==2)
            {
                if(a[i][j]>=a[i][j-1]||a[i][j]>=a[i][j+1])
                {
                    r_2+=1;
                }
            }
            if(j==3)
            {
                if(a[i][j]>=a[i][j-1]||a[i][j]>=a[i][j-2])
                {
                    r_3+=1;
                }
            }
        }
    }
    if(r_1<=n/2||r_2<=n/2||r_3<=n/2)
    {
        for(int i=1;i<=n;i++)
        {
        for(int j=1;j<=3;j++)
        {
            if(j==1)
            {
                if(a[i][j]>=a[i][j+1]||a[i][j]>=a[i][j+2])
                {
                    cnt+=a[i][j];
                }
            }
            if(j==2)
            {
                if(a[i][j]>=a[i][j-1]||a[i][j]>=a[i][j+2])
                {
                    cnt+=a[i][j];
                }
            }
            if(j==3)
            {
                if(a[i][j]>=a[i][j-1]||a[i][j]>=a[i][j-2])
                {
                    cnt+=a[i][j];
                }
            }
        }
        }
        cout<<cnt<<endl
    }
    if(r_1>n/2)
    {
        for(int i=1;i<=n;i++)
        {
            z=min(z,a[i][1]);
        }
    }
    if(r_2>n/2)
    {
        for(int i=1;i<=n;i++)
        {
            x=min(x,a[i][2]);
        }
    }
    if(r_3>n/2)
    {
        for(int i=1;i<=n;i++)
        {
            y=min(y,a[i][3]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(j==1)
            {
                if(a[i][j]>=a[i][j+1]||a[i][j]>=a[i][j+2])
                {
                    if(a[i][j]==z)cnt+=max(a[i][j+1],a[i][j+2]);
                }
            }
            if(j==2)
            {
                if(a[i][j]>=a[i][j-1]||a[i][j]>=a[i][j+1])
                {
                    if(a[i][j]==x)cnt+=max(a[i][j-1],a[i][j+1]);
                }
            }
            if(j==3)
            {
                if(a[i][j]>=a[i][j-1]||a[i][j]>=a[i][j-2])
                {
                    if(a[i][j]==y)cnt+=max(a[i][j-1],a[i][j-2]);
                }
            }
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            a[i][j]=0;
        }
    }
    cnt=0;
    }
    return 0;
}
