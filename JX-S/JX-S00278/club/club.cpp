#include<bits/stdc++.h>
using namespace std;
struct ren{
    int h1=0,h2=0,h3=0;
};
int renmax(ren r){
    if(max(max(r.h1,r.h2),r.h3)==r.h1)return 1;
    if(max(max(r.h1,r.h2),r.h3)==r.h2)return 2;
    if(max(max(r.h1,r.h2),r.h3)==r.h3)return 3;
}
int renjun(ren r){
    int j1=abs(r.h1-r.h2),j2=abs(r.h3-r.h2),j3=abs(r.h1-r.h3);
    int z1=j1+j3,z2=j2+j1,z3=j2+j3;
    if(max(max(z1,z2),z3)==z1)return 1;
    if(max(max(z1,z2),z3)==z2)return 2;
    if(max(max(z1,z2),z3)==z3)return 3;
}
int renzun(ren r){
    int j1=abs(r.h1-r.h2),j2=abs(r.h3-r.h2),j3=abs(r.h1-r.h3);
    int z1=j1+j3,z2=j2+j1,z3=j2+j3;
    return max(max(z1,z2),z3);
}
bool cmp(ren x,ren y){
    return renzun(x)>renzun(y);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    for(int TEST=1;TEST<=T;TEST++){
    int n,we1=0,we2=0,we3=0;cin>>n;int we=n;
    ren rn1[n+1]={},rn2[n+1]={},rn3[n+1]={},rn[n+1]={};
    for(int i=1;i<=n;i++){
        cin>>rn[i].h1>>rn[i].h2>>rn[i].h3;
    }
    int yu=0,ans=0;
    while(yu<n){
        for(int i=1;i<=n;i++){
            cout<<rn[i].h1<<'/'<<rn[i].h2<<'/'<<rn[i].h3<<endl;
        }
        for(int i=1;i<=we;i++){
            if(renmax(rn[i])==1)rn1[we1++]=rn[i];
            if(renmax(rn[i])==2)rn2[we2++]=rn[i];
            if(renmax(rn[i])==3)rn3[we3++]=rn[i];
        cout<<renmax(rn[i])<<' '<<rn[i].h1<<'/'<<rn[i].h2<<'/'<<rn[i].h3<<endl;
            rn[i]={0,0,0};
        }
        cout<<yu<<'?'<<endl;
        we=1;
        sort(rn1+1,rn1+1+we1,cmp);
        sort(rn2+1,rn2+1+we2,cmp);
        sort(rn3+1,rn3+1+we3,cmp);
        int i;
        for(i=1;i<=n/2&&i<=we1;i++){ans+=rn1[i].h1;yu++;rn1[i]={0,0,0};cout<<ans<<' ';}
        for(;i<=we1;i++){rn1[i].h1=0;rn[we++]=rn1[i];cout<<rn1[i].h1<<'/'<<rn1[i].h2<<'/'<<rn1[i].h3<<endl;}
        for(i=1;i<=n/2&&i<=we2;i++){ans+=rn2[i].h2;yu++;rn2[i]={0,0,0};cout<<ans<<'!';}
        for(;i<=we2;i++){rn2[i].h2=0;rn[we++]=rn2[i];}
        for(i=1;i<=n/2&&i<=we3;i++){ans+=rn3[i].h3;yu++;rn3[i]={0,0,0};cout<<ans<<'$';}
        for(;i<=we3;i++){rn3[i].h3=0;rn[we++]=rn3[i];}
        cout<<endl;
        we1=0;we2=0;we3=0;
    }
    cout<<ans;
    return 0;
    }
}
