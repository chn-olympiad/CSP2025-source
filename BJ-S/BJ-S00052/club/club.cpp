#include<bits/stdc++.h>
using namespace std;
int T,a[100050][4],s[100050],b[100050];
struct ch{int c,v1,v2,vim,minn;};
bool cmp1(ch p,ch q)
{
    return p.v1<q.v1;
}
bool cmp2(ch p,ch q)
{
    return p.v2<q.v2;
}
bool cmp3(ch p,ch q)
{
    return p.vim<q.vim;
}
void print(int n)
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=a[i][b[i]];
    }
    cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        bool FA=1,FB=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0)FA=0;
            if(a[i][3]!=0)FB=0;
            if(a[i][1]==a[i][2])
            {
                if(a[i][2]==a[i][3])
                    s[i]=7;
                else if(a[i][2]>a[i][3])
                    s[i]=4;
                else
                    s[i]=3;
            }
            else if(a[i][1]>a[i][2])
            {
                if(a[i][2]>=a[i][3])
                    s[i]=1;
                else
                {
                    if(a[i][1]>a[i][3])
                        s[i]=1;
                    else if(a[i][1]==a[i][3])
                        s[i]=5;
                    else
                        s[i]=3;
                }
            }
            else
            {
                if(a[i][2]==a[i][3])
                    s[i]=6;
                else if(a[i][2]>a[i][3])
                    s[i]=2;
                else
                    s[i]=3;
            }
        }
        if(FA)
        {
            int u[100050];
            for(int i=1;i<=n;i++)
            {
                u[i]=a[i][1];
            }
            sort(u+1,u+n+1);
            int ans=0;
            for(int i=n;i>=n/2;i--)
            {
                ans+=u[i];
            }
            cout<<ans<<endl;
            break;
        }
        int x=0,y=0,z=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]==2||s[i]==6)
                y++,b[i]=2;
            else if(s[i]==3)
                z++,b[i]=3;
            else
                x++,b[i]=1;
        }
        int f=0;
        if(x>n/2)f=1;
        if(y>n/2)f=2;
        if(z>n/2)f=3;
        //cout<<f<<' '<<x<<' '<<y<<' '<<z<<' '<<endl;
        //for(int i=1;i<=n;i++)cout<<b[i]<<' ';
        //cout<<endl;
        if(f==0)
        {
            print(n);
            continue;
        }
        if(f==1)
        {
            for(int i=1;i<=n;i++)
            {
                if(s[i]==4&&y<=n/2)
                {
                    y++,x--;
                    b[i]=2;
                }
                if(s[i]==5&&z<=n/2)
                {
                    z++,x--;
                    b[i]=3;
                }
                if(s[i]==7&&(z<=n/2||y<=n/2))
                {
                    if(z<y)
                    {
                        z++,x--;
                        b[i]=3;
                    }
                    else
                    {
                        y++,x--;
                        b[i]=2;
                    }
                }
            }
            if(y==n/2&&z<n/2)
            {
                for(int i=1;i<=n;i++)
                {
                    if(s[i]==6&&z<=n/2)
                    {
                        z++,y--;
                        b[i]=3;
                    }
                    if(z==n/2)break;
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(s[i]==4&&y<=n/2)
                {
                    y++,x--;
                    b[i]=2;
                }
                if(s[i]==5&&z<=n/2)
                {
                    z++,x--;
                    b[i]=3;
                }
            }
        }
        f=0;
        if(x>n/2)f=1;
        if(y>n/2)f=2;
        if(z>n/2)f=3;
        if(f==0)
        {
            print(n);
            continue;
        }
        //cout<<f<<' '<<x<<' '<<y<<' '<<z<<' '<<endl;
        //for(int i=1;i<=n;i++)cout<<b[i]<<' ';
        //cout<<endl;
        ch m[100050];
        if(FB)
        {
            for(int i=1;i<=n;i++)
            {
                if(b[i]==3)
                {
                    y++,z--;
                    b[i]=2;
                }
            }
            f=0;
            if(x>n/2)f=1;
            if(y>n/2)f=2;
            for(int i=1;i<=n;i++)
            {
                m[i].c=i;
                m[i].v1=abs(a[i][1]-a[i][2]);
            }
            sort(m+1,m+n+1,cmp1);
            for(int i=1;i<=n;i++)
            {
                if(x==n/2&&y==n/2)break;
                if(f==1&&y<=n/2&&b[m[i].c]==1)
                {
                    y++;
                    x--;
                    b[m[i].c]=2;
                }
                if(f==2&&x<=n/2&&b[m[i].c]==2)
                {
                    x++;
                    y--;
                    b[m[i].c]=1;
                }
            }
            print(n);
            continue;
        }
        if(f==1)
        {
            for(int i=1;i<=n;i++)
            {
                m[i].c=i;
                m[i].v1=abs(a[i][1]-a[i][2]);
                m[i].v2=abs(a[i][1]-a[i][3]);
                if(m[i].v1<=m[i].v2)
                {
                    m[i].vim=m[i].v1;
                    m[i].minn=2;
                }
                else
                {
                    m[i].vim=m[i].v2;
                    m[i].minn=3;
                }
            }
            sort(m+1,m+n+1,cmp3);

            //for(int i=1;i<=n;i++)
                //cout<<m[i].c<<' '<<m[i].v1<<' '<<m[i].v2<<' '<<m[i].vim<<' '<<m[i].minn<<endl;
            for(int i=1;i<=n;i++)
            {
                if(x<=n/2)break;
                if(b[m[i].c]==1&&m[i].minn==2&&y<n/2)
                {
                    x--,y++;
                    b[m[i].c]=2;
                }
                if(b[m[i].c]==1&&m[i].minn==3&&z<n/2)
                {
                    x--,z++;
                    b[m[i].c]=3;
                }
            }
            print(n);
            continue;
        }
        if(f==2)
        {
            for(int i=1;i<=n;i++)
            {
                m[i].c=i;
                m[i].v1=abs(a[i][1]-a[i][2]);
                m[i].v2=abs(a[i][2]-a[i][3]);
                if(m[i].v1<=m[i].v2)
                {
                    m[i].vim=m[i].v1;
                    m[i].minn=1;
                }
                else
                {
                    m[i].vim=m[i].v2;
                    m[i].minn=3;
                }
            }
            sort(m+1,m+n+1,cmp3);
            for(int i=1;i<=n;i++)
            {
                if(y<=n/2)break;
                if(b[m[i].c]==2&&m[i].minn==1&&x<n/2)
                {
                    y--,x++;
                    b[m[i].c]=1;
                }
                if(b[m[i].c]==2&&m[i].minn==3&&z<n/2)
                {
                    y--,z++;
                    b[m[i].c]=3;
                }
            }
            print(n);
            continue;
        }
        if(f==3)
        {
            for(int i=1;i<=n;i++)
            {
                m[i].c=i;
                m[i].v1=abs(a[i][1]-a[i][3]);
                m[i].v2=abs(a[i][2]-a[i][3]);
                if(m[i].v1<=m[i].v2)
                {
                    m[i].vim=m[i].v1;
                    m[i].minn=1;
                }
                else
                {
                    m[i].vim=m[i].v2;
                    m[i].minn=2;
                }
            }
            sort(m+1,m+n+1,cmp3);
            for(int i=1;i<=n;i++)
            {
                if(z<=n/2)break;
                if(b[m[i].c]==3&&m[i].minn==1&&x<n/2)
                {
                    z--,x++;
                    b[m[i].c]=1;
                }
                if(b[m[i].c]==3&&m[i].minn==2&&y<n/2)
                {
                    z--,y++;
                    b[m[i].c]=2;
                }
            }
            print(n);
            continue;
        }
    }
	return 0;
}
