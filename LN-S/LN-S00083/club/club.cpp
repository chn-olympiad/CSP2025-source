#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n;
        if(n==2)
        {
            int a,aa,b,bb,c,cc;
            cin>>a>>b>>c;
            cin>>aa>>bb>>cc;
            int u,v,w,x,y,z;
            u=a+bb;
            v=a+cc;
            w=b+aa;
            x=b+cc;
            y=c+aa;
            z=c+aa;
            if(u>=v && u>=w && u>=x && u>=y && u>=z)ans=u;
            if(v>=u && v>=w && v>=x && v>=y && v>=z)ans=v;
            if(w>=v && w>=u && w>=x && w>=y && w>=z)ans=w;
            if(x>=v && x>=w && x>=u && x>=y && x>=z)ans=x;
            if(y>=v && y>=w && y>=x && y>=u && y>=z)ans=y;
            if(z>=v && z>=w && z>=x && z>=y && z>=u)ans=z;
            cout<<ans<<endl;
        }
        else
        {
            int maxa=-99999999;
            int maxb=-99999999;
            int maxc=-99999999;
            for(int i=0;i<n;i++)
            {
                cin>>a[i]>>b[i]>>c[i];
                maxa=max(a[i],maxa);
                maxb=max(b[i],maxb);
                maxc=max(c[i],maxc);
            }
            cout<<maxa+maxb+maxc<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
