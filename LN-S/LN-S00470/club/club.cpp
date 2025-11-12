#include<bits/stdc++.h>
using namespace std;
int a[101000],b[101000],c[101000];
int inda[101000],indb[101000],indc[101000];
int cnta,cntb,cntc;
int ia=0,ib=0,ic=0;
int x[101000],y[101000],z[101000];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m=n/2;
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i]>>z[i];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int w=max(x[i],max(y[i],z[i]));
            ans+=w;
            if(x[i]==w)
                a[ia]=x[i]-max(y[i],z[i]),inda[i]=i,ia++;
            else if(y[i]==w)
                b[ib]=y[i]-max(x[i],z[i]),indb[i]=i,ib++;
            else
                c[ic]=z[i]-max(y[i],x[i]),indc[i]=i,ic++;
        }
        sort(inda,inda+ia,[&](int i,int j)->bool{
             return a[i]<a[j];
             });
        int i=0;
        while(ia>m)
        {
            ans-=a[inda[i]];
            if(a[inda[i]]==x[inda[i]]-y[inda[i]])
                ib++;
            else
                ic++;
            i++;
            ia--;
        }
        sort(indb,indb+ib,[&](int i,int j)->bool{
             return b[i]<b[j];
             });
        i=0;
        while(ib>m)
        {
            ans-=y[indb[i]]-z[indb[i]];
            ib--;
            i++;
        }
        cout<<ans<<endl;
        ia=0,ib=0,ic=0;
        cnta=0;
        cntb=0;
        cntc=0;
    }
    return 0;
}
