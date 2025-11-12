#include<bits/stdc++.h>
using namespace std;
struct club
{
    int num,d;
}b[100005];

int n,T,sum;
int a[100005][4];
int c[4];

void compare(int x)
{
    if(a[x][1]>=a[x][2]&&a[x][1]>=a[x][3])
    {
        b[x].d=1;b[x].num=a[x][1];
    }
    if(a[x][2]>=a[x][1]&&a[x][2]>=a[x][3])
    {
        b[x].d=2;b[x].num=a[x][2];
    }
    if(a[x][3]>=a[x][2]&&a[x][3]>=a[x][1])
    {
        b[x].d=3;b[x].num=a[x][3];
    }
}
void f(int l,int r)
{
    if(l==r)return;
    int i=l,j=r,mid=(l+r)/2;
    while(i<j)
    {
        while(b[i].num>b[mid].num)i++;
        while(b[j].num<b[mid].num)j--;
        swap(b[i],b[j]);
        i++;j--;
    }
    f(l,mid);
    f(mid+1,r);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        memset(b,0,sizeof(b));
        sum=0;
        c[1]=n/2;c[2]=n/2;c[3]=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            compare(i);
        }
        f(1,n);
        int k=0,g=0;
        for(int i=1;i<=n;i++)
        {
            if(c[b[i].d]>=1)
            {
                sum+=b[i].num;
                c[b[i].d]--;
            }
            else
            {
                k=i;
                g=b[i].d;
                break;
            }
        }
        cout<<sum<<'\n';
    }
    return 0;
}