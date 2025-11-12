#include<bits/stdc++.h>
using namespace std;
#define int long long
int fx(int a,int b)
{
    if(a==1&&b==2)
        return 3;
    if(a==1&&b==3)
        return 2;
    if(a==2&&b==3)
        {return 1;
        //cout<<"dsfifsdi";
        }
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int a;
    cin>>a;
    while(a--)
    {
        int b,sum=0;
        cin>>b;
        int c[b+1],d[b+1],e[b+1],zz[b+1],lz[b+1],kl1=0,kl2=0,kl3=0;
        for(int i=1;i<b;i++)
            c[i]=0;
        for(int i=1;i<b;i++)
            d[i]=0;
        for(int i=1;i<b;i++)
            e[i]=0;
        for(int i=1;i<=b;i++)
        {
            cin>>c[i]>>d[i]>>e[i];
            int gh=min(c[i],min(d[i],e[i]));
            c[i]-=gh,d[i]-=gh,e[i]-=gh;
            if(c[i]==0)
                {
                lz[i]=1;
                if(max(d[i],e[i])==d[i])
                    zz[i]=2;
                else zz[i]=3;
                }
            if(d[i]==0)
                {lz[i]=2;
                if(max(c[i],e[i])==e[i])
                    zz[i]=3;
                else zz[i]=1;
                }
            if(e[i]==0){
                    lz[i]=3;
                    if(max(c[i],d[i])==c[i])
                    zz[i]=1;
                    else zz[i]=2;
                        }
            sum+=gh;
        }
        int c1[b/2+1][3],d1[b/2+1][3],e1[b/2+1][3],q=0,r=0,s=0;
        for(int i=1;i<=b/2;i++)
            c1[i][0]=0,c1[i][1]=0,c1[i][2]=0,d1[i][0]=0,d1[i][1]=0,d1[i][2]=0,e1[i][0]=0,e1[i][1]=0,e1[i][2]=0;
        for(int i=1;i<=b;i++)
        {
            if(zz[i]==1)
            {
                  c1[++q][0]=c[i];
                  c1[q][1]=fx(1,lz[i]);
                  c1[q][2]=i;
                  //cout<<"1:"<<c1[q][0]<<" "<<c1[q][1]<<endl;
            }
            if(zz[i]==2)
            {
                d1[++r][0]=d[i];
                if(lz[i]==1)
                    d1[r][1]=3;
                if(lz[i]==3)
                    d1[r][1]=1;
                d1[r][2]=i;
               // cout<<d1[r][0]<<" "<<d1[r][1]<<endl;
            }
            if(zz[i]==3)
            {
                e1[++s][0]=e[i];
                e1[s][1]=fx(lz[i],zz[i]);
                e1[s][2]=i;
                //cout<<"3:"<<e1[s][0]<<" "<<e1[s][1]<<endl;
            }
            //cout<<sum<<endl;
        }
        if(q>b/2)
        {
            int hhh[q+1],iuy=0;
            for(int i=0;i<=q;i++)
                hhh[i]=0;
            for(int i=1;i<=q;i++)
            {
                int hzg=0;
                if(c1[i][1]==1)
                     hzg=c[c1[i][2]];
                if(c1[i][1]==2)
                     hzg=d[c1[i][2]];
                if(c1[i][1]==3)
                     hzg=e[c1[i][2]];
                c1[i][0]-=hzg;
                //cout<<c1[i][0]<<" ";
                sum+=hzg;
                hhh[++iuy]=c1[i][0];
            }
         //   cout<<endl<<sum<<endl;
            sort(hhh+1,hhh+q+1);
            for(int i=q;i>q-(b/2);i--)
                sum+=hhh[i];
               // cout<<sum<<endl;
                kl1=1;
        }
        if(r>b/2)
        {
            int hhh[r+1],iuy=0;
            for(int i=0;i<=r;i++)
                hhh[i]=0;
            for(int i=1;i<=r;i++)
            {
                int hzg=0;
                if(d1[i][1]==1)
                     hzg=c[d1[i][2]];
                if(d1[i][1]==2)
                     hzg=d[d1[i][2]];
                if(d1[i][1]==3)
                     hzg=e[d1[i][2]];
                d1[i][0]-=hzg;
              //  cout<<hzg<<" ";
                sum+=hzg;
                hhh[++iuy]=d1[i][0];
                kl2=1;
            }
         //   cout<<endl<<sum<<endl;
            sort(hhh+1,hhh+r+1);
            for(int i=r;i>r-(b/2);i--)
                sum+=hhh[i];
             //   cout<<sum<<endl;
        }
        if(s>b/2)
        {
            int hhh[s+1],iuy=0;
            for(int i=0;i<=s;i++)
                hhh[i]=0;
            for(int i=1;i<=s;i++)
            {
                int hzg=0;
                if(e1[i][1]==1)
                     hzg=c[e1[i][2]];
                if(e1[i][1]==2)
                     hzg=d[e1[i][2]];
                if(e1[i][1]==3)
                     hzg=e[e1[i][2]];
             //   e1[i][0]-=hzg;
               // cout<<hzg<<" ";
                sum+=hzg;
                hhh[++iuy]=c1[i][0];
                kl3=1;
            }
            //cout<<endl<<sum<<endl;
            sort(hhh+1,hhh+s+1);
            for(int i=s;i>s-(b/2);i--)
                sum+=hhh[i];
               // cout<<sum<<endl;
        }
       // cout<<sum<<endl;
        if(kl1!=1)
            for(int i=1;i<=q;i++)
            sum+=c1[i][0];
        if(kl2!=1)
            for(int i=1;i<=r;i++)
            sum+=d1[i][0];
        if(kl3!=1)
            for(int i=1;i<=s;i++)
            sum+=e1[i][0];
        cout<<sum<<endl;
    }
}
