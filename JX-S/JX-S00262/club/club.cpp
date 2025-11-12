#include<bits/stdc++.h>
using namespace std;
//delete the double Fe tube before freopen before you upload!!!
int t;
bool cmp(int x,int y)
{
    return x>y;
}
struct club
{
    int tot=0,pn=0,minn=100000,love[50005];
};
struct p
{
    int love[5],lrank[5];
};
int rep(int tot,int rp,int min1)
{
    return tot+rp-min1;
}
int main()
{
    freopen("club1.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        //cout<<"t="<<i<<endl;
        int n,ans=0;
        p a[100005];
        club clb[5];
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=3;k++)
            {
                cin>>a[j].love[k];
            }
            if(a[j].love[1]>=a[j].love[2]&&a[j].love[2]>=a[j].love[3])
            {
                a[j].lrank[1]=1;
                a[j].lrank[2]=2;
                a[j].lrank[3]=3;
            }//123
            if(a[j].love[1]>=a[j].love[3]&&a[j].love[3]>=a[j].love[2])
            {
                a[j].lrank[1]=1;
                a[j].lrank[2]=3;
                a[j].lrank[3]=2;
            }//132
            if(a[j].love[2]>=a[j].love[1]&&a[j].love[1]>=a[j].love[3])
            {
                a[j].lrank[1]=2;
                a[j].lrank[2]=1;
                a[j].lrank[3]=3;
            }//213
            if(a[j].love[2]>=a[j].love[3]&&a[j].love[3]>=a[j].love[1])
            {
                a[j].lrank[1]=2;
                a[j].lrank[2]=3;
                a[j].lrank[3]=1;
            }//231
            if(a[j].love[3]>=a[j].love[1]&&a[j].love[1]>=a[j].love[2])
            {
                a[j].lrank[1]=3;
                a[j].lrank[2]=1;
                a[j].lrank[3]=2;
            }//312
            if(a[j].love[3]>=a[j].love[2]&&a[j].love[2]>=a[j].love[1])
            {
                a[j].lrank[1]=3;
                a[j].lrank[2]=2;
                a[j].lrank[3]=1;
            }//321
        }
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=3;k++)
            {
                //cout<<j<<".love rank"<<k<<" is"<<a[j].lrank[k]<<endl;
            }
            //cout<<endl;
        }
        for(int j=1;j<=n;j++)
        {
            if(clb[a[j].lrank[1]].pn==0)
            {
                clb[a[j].lrank[1]].love[1]=a[j].love[a[j].lrank[1]];
                clb[a[j].lrank[1]].pn++;
                clb[a[j].lrank[1]].minn=a[j].love[a[j].lrank[1]];
                clb[a[j].lrank[1]].tot+=a[j].love[a[j].lrank[1]];
            }//direct join
            else if(clb[a[j].lrank[1]].pn<n/2)
            {
                clb[a[j].lrank[1]].pn++;
                clb[a[j].lrank[1]].love[clb[a[j].lrank[1]].pn]=a[j].love[a[j].lrank[1]];
                clb[a[j].lrank[1]].tot+=a[j].love[a[j].lrank[1]];
                sort(clb[a[j].lrank[1]].love+1,clb[a[j].lrank[1]].love+clb[a[j].lrank[1]].pn+1,cmp);
                clb[a[j].lrank[1]].minn=clb[a[j].lrank[1]].love[clb[a[j].lrank[1]].pn];
            }//join the lovest
            else
            {
                int rp[5];
                rp[1]=clb[a[j].lrank[1]].tot+a[j].love[a[j].lrank[1]]-clb[a[j].lrank[1]].minn;
                rp[2]=clb[a[j].lrank[2]].tot+a[j].love[a[j].lrank[2]];
                rp[3]=clb[a[j].lrank[3]].tot+a[j].love[a[j].lrank[3]];
                if(rp[1]>=rp[2]&&rp[1]>=rp[3])
                {
                    clb[a[j].lrank[1]].tot+=a[j].love[a[j].lrank[1]];
                    clb[a[j].lrank[1]].tot-=clb[a[j].lrank[1]].minn;
                    clb[a[j].lrank[1]].love[clb[a[j].lrank[1]].pn]=a[j].love[a[j].lrank[1]];
                    sort(clb[a[j].lrank[1]].love+1,clb[a[j].lrank[1]].love+clb[a[j].lrank[1]].pn+1,cmp);

                }//join 1
                else if(rp[2]>=rp[1]&&rp[2]>=rp[3])
                {
                    clb[a[j].lrank[2]].pn++;
                    clb[a[j].lrank[2]].tot=rp[2];
                    sort(clb[a[j].lrank[2]].love+2,clb[a[j].lrank[2]].love+clb[a[j].lrank[2]].pn+1,cmp);

                }//join 2
                else
                {
                    clb[a[j].lrank[3]].tot+=a[j].love[a[j].lrank[3]];
                    clb[a[j].lrank[3]].pn++;
                    sort(clb[a[j].lrank[3]].love+1,clb[a[j].lrank[3]].love+clb[a[j].lrank[3]].pn+1,cmp);

                }//join 3

            }
        }
        for(int j=1;j<=3;j++)
        {
            //cout<<"club"<<j<<" tot="<<clb[j].tot<<endl;
            ans+=clb[j].tot;
        }
        cout<<ans<<endl;
    }
    return 0;
}
