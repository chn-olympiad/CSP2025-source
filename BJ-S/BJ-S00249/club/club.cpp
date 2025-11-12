#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int t,n,cntx,cnty,cntz,f;
struct node{
    int x,y,z,mx;
};
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    while(t--){
        node a[N]={};
        cntx=0,cnty=0,cntz=0,f=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].z) f=1;
        }
        for(int i=1;i<=n;i++){
            a[i].mx=max(a[i].x,max(a[i].y,a[i].z));
            if(a[i].mx==a[i].x){
                cntx++;
            }else if(a[i].mx==a[i].y){
                cnty++;
            }else{
                cntz++;
            }
        }
        int maxn=n/2;
        while(cntx>maxn){
            int idx,maxzh=20005;
            for(int i=1;i<=n;i++){
                if(a[i].mx==a[i].x&&min(abs(a[i].x-a[i].y),abs(a[i].x-a[i].z))<maxzh){
                    maxzh=min(abs(a[i].x-a[i].y),abs(a[i].x-a[i].z));
                    idx=i;
                }
            }
            cntx--;
            if(a[idx].x-a[idx].y<a[idx].x-a[idx].z||!f){
                a[idx].mx=a[idx].y;
                cnty++;
            }else{
                a[idx].mx=a[idx].z;
                cntz++;
            }
        }
        while(cnty>maxn){
            int idx,maxzh=20005;
            for(int i=1;i<=n;i++){
                if(a[i].mx==a[i].y&&min(abs(a[i].y-a[i].x),abs(a[i].y-a[i].z))<maxzh){
                    maxzh=min(abs(a[i].y-a[i].x),abs(a[i].y-a[i].z));
                    idx=i;
                }
            }
            cnty--;
            if(cntx<maxn&&a[idx].y-a[idx].x<a[idx].y-a[idx].z||!f){
                a[idx].mx=a[idx].x;
                cntx++;
            }else{
                a[idx].mx=a[idx].z;
                cntz++;
            }
        }
        while(f&&cntz>maxn){
            int idx,maxzh=20005;
            for(int i=1;i<=n;i++){
                if(a[i].mx==a[i].z&&min(abs(a[i].z-a[i].y),abs(a[i].z-a[i].x))<maxzh){
                    maxzh=min(abs(a[i].z-a[i].y),abs(a[i].z-a[i].x));
                    idx=i;
                }
            }
            cntz--;
            if(cnty<maxn&&a[idx].z-a[idx].y<a[idx].z-a[idx].x){
                a[idx].mx=a[idx].y;
                cnty++;
            }else if(cntx<maxn){
                a[idx].mx=a[idx].x;
                cntx++;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=a[i].mx;
        }
        cout<<ans<<endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
