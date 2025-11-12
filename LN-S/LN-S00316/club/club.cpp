#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0;
int p[4];
struct love
{
	int num,w;
};
	
struct mber
{
    love l[4];
}m[100005];

bool cmp2(love x,love y)
{
	return x.w>y.w;
}

bool cmp1(mber x,mber y)
{
    return x.l[1].w>y.l[1].w;
}

void add(mber x)
{
    for(int i=1;i<=3;i++)
        if(p[x.l[i].num]<(n/2))
        {   
            ans+=x.l[i].w;
            p[x.l[i].num]++;
            return ;
        }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(p,0,sizeof(p));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>m[i].l[1].w>>m[i].l[2].w>>m[i].l[3].w;
            m[i].l[1].num=1;
            m[i].l[2].num=2;
            m[i].l[3].num=3;
            sort(m[i].l+1,m[i].l+4,cmp2);   //只能在main里用. why?
        }
        sort(m+1,m+1+n,cmp1);
        for(int i=1;i<=n;i++)
        {
            add(m[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
