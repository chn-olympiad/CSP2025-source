#include<bits/stdc++.h>
using namespace std;
int n,T,x[100005],y[100005],z[100005],tx,ty,tz,m,ans,t;
struct node{
    int id,v;
    bool friend operator > (const node &x,const node &y)
      { return x.v>y.v; }
    bool friend operator<(const node& x, const node& y)
      { return x.v<y.v; }
};
int xx[4][100005],xxx[4][100005],t1,tt;
struct node1
{
    int aa[4],w;
}f[100005][4];
struct ed{
    int id,maxn;
}q[100005];
bool cmp(ed a,ed b){return a.maxn>b.maxn;}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin>>T;
    while(T--)
    {
		priority_queue<node,vector<node>,greater<node> >a,b,c;
        cin>>n;
        for(int i=1,yy=0;i<=n;i++)
        {
            for(int j=1;j<4;j++)
            {
                cin>>xxx[j][i];
                yy=max(yy,xxx[j][i]);
            }
            x[i]=xxx[1][i];
            y[i]=xxx[2][i];
            z[i]=xxx[3][i];
            q[i].id=i;
            q[i].maxn=yy;
        }
        sort(q+1,q+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<4;j++)
            {
                xx[j][i]=xxx[j][q[i].id];
                //cout<<x[j][i]<<" ";
                if(i==1)
                {
                    f[i][j].w=xx[j][i];
                    f[i][j].aa[j]=1;
                }
            }
           // cout<<endl;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<4;j++)
            {
				t1=-1;
				tt=0;
				for(int k=1;k<4;k++)
				{
					if(f[i-1][k].aa[j]<n/2)
					{
						if(f[i-1][k].w>t1)
						{
							t1=f[i-1][k].w;
							tt=k;
						}
					}
				}
                f[i][j].aa[j]=f[i-1][tt].aa[j]+1;
                for(int k=1;k<4;k++)
                {
                    if(k==j)continue;
                    //cout<<f[i-1][t].a[k]<<endl;
                    f[i][j].aa[k]=f[i-1][tt].aa[k];
                }
                f[i][j].w=f[i-1][tt].w+xx[j][i];
				//cout<<i<<" "<<j<<" "<<t<<endl;
				//for(int ii=1;ii<4;ii++)cout<<f[i][j].a[ii]<<" ";
				//cout<<endl;
            }
        }
        ans=0;
        tx=ty=tz=0;
        for(int i=1;i<=n;i++)
        {
            if(x[i]>=y[i]&&x[i]>=z[i])
            {
                if(tx<n/2)
                {
                    tx++;
                    a.push({i,x[i]});
                    ans+=x[i];
                }
                else{
                    if(a.top().v<x[i])
                    {
                        ans=ans+x[i]-a.top().v;
                        t=a.top().id;
                        if(y[t]>z[t])ans+=y[t];
                        else ans+=z[t];
                        a.pop();
                        a.push({i,x[i]});
                    }
                    else if(y[i]>z[i])
                    {
                        if(ty<n/2)
                        {
                            ty++;
                            a.push({i,y[i]});
                            ans+=y[i];
                        }
                        else{
                            if(a.top().v<y[i])
                            {
                                ans=ans+y[i]-a.top().v;
                                t=a.top().id;
                                if(x[t]>z[t])ans+=x[t];
                                else ans+=z[t];
                                a.pop();
                                a.push({i,y[i]});
                            }
                            else{
                                tz++;
                                a.push({i,z[i]});
                                ans+=z[i];
                            }
                        }
                    }
                    else{
                        if(tz<n/2)
                        {
                            tz++;
                            a.push({i,z[i]});
                            ans+=z[i];
                        }
                        else{
                            if(a.top().v<z[i])
                            {
                                ans=ans+z[i]-a.top().v;
                                t=a.top().id;
                                if(x[t]>y[t])ans+=x[t];
                                else ans+=y[t];
                                a.pop();
                                a.push({i,z[i]});
                            }
                            else{
                                ty++;
                                a.push({i,y[i]});
                                ans+=y[i];
                            }
                        }
                    }
                }
            }
            else if(y[i]>=x[i]&&y[i]>=z[i])
            {
                if(ty<n/2)
                {
                    ty++;
                    a.push({i,y[i]});
                    ans+=y[i];
                }
                else{
                    if(a.top().v<y[i])
                    {
                        ans=ans+y[i]-a.top().v;
                        t=a.top().id;
                        if(x[t]>z[t])ans+=x[t];
                        else ans+=z[t];
                        a.pop();
                        a.push({i,y[i]});
                    }
                    else if(x[i]>z[i])
                    {
                        if(tx<n/2)
                        {
                            tx++;
                            a.push({i,x[i]});
                            ans+=x[i];
                        }
                        else{
                            if(a.top().v<x[i])
                            {
                                ans=ans+x[i]-a.top().v;
                                t=a.top().id;
                                if(y[t]>z[t])ans+=y[t];
                                else ans+=z[t];
                                a.pop();
                                a.push({i,x[i]});
                            }
                            else{
                                tz++;
                                a.push({i,z[i]});
                                ans+=z[i];
                            }
                        }
                    }
                    else{
                        if(tz<n/2)
                        {
                            tz++;
                            a.push({i,z[i]});
                            ans+=z[i];
                        }
                        else{
                            if(a.top().v<z[i])
                            {
                                ans=ans+z[i]-a.top().v;
                                t=a.top().id;
                                if(x[t]>y[t])ans+=x[t];
                                else ans+=y[t];
                                a.pop();
                                a.push({i,z[i]});
                            }
                            else{
                                ty++;
                                a.push({i,y[i]});
                                ans+=y[i];
                            }
                        }
                    }
                }
            }
            else if(z[i]>=y[i]&&z[i]>=x[i])
            {
                if(tz<n/2)
                {
                    tz++;
                    a.push({i,z[i]});
                    ans+=z[i];
                }
                else{
                    if(a.top().v<z[i])
                    {
                        ans=ans+z[i]-a.top().v;
                        t=a.top().id;
                        if(y[t]>x[t])ans+=y[t];
                        else ans+=x[t];
                        a.pop();
                        a.push({i,z[i]});
                    }
                    else if(y[i]>x[i])
                    {
                        if(ty<n/2)
                        {
                            ty++;
                            a.push({i,y[i]});
                            ans+=y[i];
                        }
                        else{
                            if(a.top().v<y[i])
                            {
                                ans=ans+y[i]-a.top().v;
                                t=a.top().id;
                                if(x[t]>z[t])ans+=x[t];
                                else ans+=z[t];
                                a.pop();
                                a.push({i,y[i]});
                            }
                            else{
                                tz++;
                                a.push({i,z[i]});
                                ans+=z[i];
                            }
                        }
                    }
                    else{
                        if(tx<n/2)
                        {
                            tx++;
                            a.push({i,x[i]});
                            ans+=x[i];
                        }
                        else{
                            if(a.top().v<x[i])
                            {
                                ans=ans+x[i]-a.top().v;
                                t=a.top().id;
                                if(y[t]>z[t])ans+=y[t];
                                else ans+=z[t];
                                a.pop();
                                a.push({i,x[i]});
                            }
                            else{
                                tz++;
                                a.push({i,z[i]});
                                ans+=z[i];
                            }
                        }
                    }
                }

            }
        }
        cout<<max(max(max(ans,f[n][1].w),f[n][2].w),f[n][3].w)<<endl;
    }
    return 0;
}
