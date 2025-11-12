#include<bits/stdc++.h>
using namespace std;
struct cz
{
string a,b;
int cd;
}c[2000010];
int n,q;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i].a>>c[i].b;
        c[i].a=' '+c[i].a;
        c[i].b=' '+c[i].b;
        c[i].cd=c[i].a.size()-1;
    }
    for(int i=1;i<=q;i++)
    {
         bool pp[2001][2001]={0},kp[1001]={0};
         int ans=0,ps[1001]={0},sl=0,pst[1001]={0},psw[1001]={0};
        string x,y;
        cin>>x>>y;
        x=' '+x;
        y=' '+y;
        int l=x.size()-1;
        for(int s=1;s<=l;s++)
        {
            string xz,yz;
            xz=' ',yz=' ';
           for(int t=s;t<=l;t++)
           {
               xz=xz+x[t],yz=yz+y[t];
               if(xz==yz){
                    pp[s][t]=1;
               }
               for(int j=1;j<=n;j++)
               {
                   if((t-s)+1==c[j].cd && xz==c[j].a && yz==c[j].b)
                   {
                       sl++;
                       pp[s][t]=1;
                       pst[sl]=s;
                       psw[sl]=t;
                       ps[sl]=j;
                       kp[j]=1;
                   }
               }
            // cout<<i<<' '<<xz<<'-'<<yz<<':'<<pp[s][t]<<endl;
           }
        }
      //  cout<<sl<<endl;
        pp[0][0]=1,pp[l+1][l+1]=1;
        for(int j=1;j<=sl;j++)
        {
            int d=ps[j];
            int ys=pst[j],yt=psw[j],xt=ys-1,zs=yt+1,xs=1,zt=l;
           // cout<<d<<':'<<ys<<','<<yt<<endl;
            if(xt<1)xs=0;
            if(zs>l)zt=l+1;
            if(pp[xs][xt] && pp[ys][yt] && pp[zs][zt])
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
