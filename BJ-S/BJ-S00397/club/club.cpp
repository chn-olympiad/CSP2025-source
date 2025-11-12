#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],c[100010],sa,sb,sc,sm,l[100010],ll[100010],ls;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%d",&n);
        sa=sb=sc=sm=ls=0;
        for(int i=1;i<=n;i++) a[i]=b[i]=c[i]=l[i]=ll[i]=0;
        for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
        for(int i=1;i<=n;i++){
            if(a[i]>=b[i]&&a[i]>=c[i]) sa++,sm+=a[i],l[i]=a[i]-max(b[i],c[i]),ll[i]=1;
            if(a[i]<b[i]&&b[i]>=c[i]) sb++,sm+=b[i],l[i]=b[i]-max(a[i],c[i]),ll[i]=2;
            if(c[i]>b[i]&&a[i]<c[i]) sc++,sm+=c[i],l[i]=c[i]-max(b[i],a[i]),ll[i]=3;
        }
        if(sa>=sb&&sa>=sc){
            if(sa<=n/2){
                cout<<sm<<endl;
                continue;
            }
            else{
                sa-=n/2;
                for(int i=1;i<=n;i++) if(ll[i]==1) ls++,l[ls]=l[i];
                sort(l+1,l+ls+1,cmp);
                for(int i=1;i<=sa;i++) sm-=l[i];
                cout<<sm<<endl;
                continue;
            }
        }
        if(sa<sb&&sb>=sc){
            if(sb<=n/2){
                cout<<sm<<endl;
                continue;
            }
            else{
                sb-=n/2;
                for(int i=1;i<=n;i++) if(ll[i]==2) ls++,l[ls]=l[i];
                sort(l+1,l+ls+1,cmp);
                for(int i=1;i<=sb;i++) sm-=l[i];
                cout<<sm<<endl;
                continue;
            }
        }
        if(sb<sc&&sa<sc){
            if(sc<=n/2){
                cout<<sm<<endl;
                continue;
            }
            else{
                sc-=n/2;
                for(int i=1;i<=n;i++) if(ll[i]==3) ls++,l[ls]=l[i];
                sort(l+1,l+ls+1,cmp);
                for(int i=1;i<=sc;i++) sm-=l[i];
                cout<<sm<<endl;
                continue;
            }
        }
    }
    return 0;
}
