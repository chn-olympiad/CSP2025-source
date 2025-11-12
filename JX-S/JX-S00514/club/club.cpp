#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
int t,n;
int maxab=0,maxa=0,maxb=0,cnta=0,cntb=0,cntc=0;
struct node{
    int aa;
    int bb;
    int cc;
};
bool cmpa(node a,node b){
    return a.aa+a.bb+a.cc>b.aa+b.bb+b.cc;
}
bool cmpb(node a,node b){
    return a.aa+a.bb+a.cc<b.aa+b.bb+b.cc;
}
bool cmpc(node a,node b){
    return a.aa>b.aa;
}
bool cmpd(node a,node b){
    return a.bb>b.bb;
}
bool cmpe(node a,node b){
    return a.cc>b.cc;
}

node a[N];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        maxab=0;cnta=0,cntb=0,cntc=0;
        for(int i=1;i<=n;i++){
            a[i].aa=0;a[i].bb=0;a[i].cc=0;
            cin>>a[i].aa>>a[i].bb>>a[i].cc;
        }
        //no sort
        for(int i=1;i<=n;i++){
            maxb+=max(a[i].aa,a[i].bb);
            maxa+=max(maxb,a[i].cc);
            maxb=0;
            if(a[i].aa==max(a[i].aa,a[i].bb)&&a[i].aa==max(a[i].aa,a[i].cc)){
                cnta++;
                //cout<<i<<"a ";
            }else if(a[i].bb==max(a[i].aa,a[i].bb)&&a[i].bb==max(a[i].bb,a[i].cc)){
                cntb++;
                //cout<<i<<"b ";
            }else{
                cntc++;
                //cout<<i<<"c ";
            }
            //cout<<i<<cnta<<cntb<<cntc<<endl;
            if(cnta>n/2){
                maxa-=a[i].aa;
                cnta--;
                maxa+=a[i].bb;
                cntb++;
                //cout<<i<<"to b ";
            }if(cntb>n/2){
                maxa-=a[i].bb;
                cntb--;
                maxa+=a[i].cc;
                cntc++;
                //cout<<i<<"to c ";
            }if(cntc>n/2){
                maxa-=a[i].cc;
                cntc--;
                maxa+=a[i].aa;
                cnta++;
                //cout<<i<<"to a ";
            }if(cnta>n/2){
                maxa-=a[i].aa;
                cnta--;
                maxa+=a[i].bb;
                cntb++;
                //cout<<i<<"to b ";
            }
        }

        cnta=0,cntb=0,cntc=0;
        maxab=maxa;
        maxa=0;
        sort(a+1,a+n+1,cmpa);
        //sorta
        for(int i=1;i<=n;i++){
            maxb+=max(a[i].aa,a[i].bb);
            maxa+=max(maxb,a[i].cc);
            maxb=0;
            if(a[i].aa==max(a[i].aa,a[i].bb)&&a[i].aa==max(a[i].aa,a[i].cc)){
                cnta++;
            }else if(a[i].bb==max(a[i].aa,a[i].bb)&&a[i].bb==max(a[i].bb,a[i].cc)){
                cntb++;
            }else{
                cntc++;
            }
            if(cnta>n/2){
                maxa-=a[i].aa;
                cnta--;
                maxa+=a[i].bb;
                cntb++;
            }if(cntb>n/2){
                maxa-=a[i].bb;
                cntb--;
                maxa+=a[i].cc;
                cntc++;
            }if(cntc>n/2){
                maxa-=a[i].cc;
                cntc--;
                maxa+=a[i].aa;
                cnta++;
            }if(cnta>n/2){
                maxa-=a[i].aa;
                cnta--;
                maxa+=a[i].bb;
                cntb++;
            }
        }
        //sortb
        cnta=0,cntb=0,cntc=0;
        maxab=max(maxab,maxa);
        maxa=0;
        sort(a+1,a+n+1,cmpb);

        for(int i=1;i<=n;i++){
            maxb+=max(a[i].aa,a[i].bb);
            maxa+=max(maxb,a[i].cc);
            maxb=0;
            if(a[i].aa==max(a[i].aa,a[i].bb)&&a[i].aa==max(a[i].aa,a[i].cc)){
                cnta++;
            }else if(a[i].bb==max(a[i].aa,a[i].bb)&&a[i].bb==max(a[i].bb,a[i].cc)){
                cntb++;
            }else{
                cntc++;
            }
            if(cnta>n/2){
                maxa-=a[i].aa;
                cnta--;
                maxa+=a[i].bb;
                cntb++;
            }if(cntb>n/2){
                maxa-=a[i].bb;
                cntb--;
                maxa+=a[i].cc;
                cntc++;
            }if(cntc>n/2){
                maxa-=a[i].cc;
                cntc--;
                maxa+=a[i].aa;
                cnta++;
            }if(cnta>n/2){
                maxa-=a[i].aa;
                cnta--;
                maxa+=a[i].bb;
                cntb++;
            }
        }
        //sortc
        cnta=0,cntb=0,cntc=0;
        maxab=max(maxab,maxa);
        maxa=0;
        sort(a+1,a+n+1,cmpc);

        for(int i=1;i<=n;i++){
            maxb+=max(a[i].aa,a[i].bb);
            maxa+=max(maxb,a[i].cc);
            maxb=0;
            if(a[i].aa==max(a[i].aa,a[i].bb)&&a[i].aa==max(a[i].aa,a[i].cc)){
                cnta++;
            }else if(a[i].bb==max(a[i].aa,a[i].bb)&&a[i].bb==max(a[i].bb,a[i].cc)){
                cntb++;
            }else{
                cntc++;
            }
            if(cnta>n/2){
                maxa-=a[i].aa;
                cnta--;
                maxa+=a[i].bb;
                cntb++;
            }if(cntb>n/2){
                maxa-=a[i].bb;
                cntb--;
                maxa+=a[i].cc;
                cntc++;
            }if(cntc>n/2){
                maxa-=a[i].cc;
                cntc--;
                maxa+=a[i].aa;
                cnta++;
            }if(cnta>n/2){
                maxa-=a[i].aa;
                cnta--;
                maxa+=a[i].bb;
                cntb++;
            }
        }
        //sortd
        cnta=0,cntb=0,cntc=0;
        maxab=max(maxab,maxa);
        maxa=0;
        sort(a+1,a+n+1,cmpd);
        for(int i=1;i<=n;i++){
            maxb+=max(a[i].aa,a[i].bb);
            maxa+=max(maxb,a[i].cc);
            maxb=0;
            if(a[i].aa==max(a[i].aa,a[i].bb)&&a[i].aa==max(a[i].aa,a[i].cc)){
                cnta++;
            }else if(a[i].bb==max(a[i].aa,a[i].bb)&&a[i].bb==max(a[i].bb,a[i].cc)){
                cntb++;
            }else{
                cntc++;
            }
            if(cnta>n/2){
                maxa-=a[i].aa;
                cnta--;
                maxa+=a[i].bb;
                cntb++;
            }if(cntb>n/2){
                maxa-=a[i].bb;
                cntb--;
                maxa+=a[i].cc;
                cntc++;
            }if(cntc>n/2){
                maxa-=a[i].cc;
                cntc--;
                maxa+=a[i].aa;
                cnta++;
            }if(cnta>n/2){
                maxa-=a[i].aa;
                cnta--;
                maxa+=a[i].bb;
                cntb++;
            }
        }
        //sorte
        cnta=0,cntb=0,cntc=0;
        maxab=max(maxab,maxa);
        maxa=0;
        sort(a+1,a+n+1,cmpe);

        for(int i=1;i<=n;i++){
            maxb+=max(a[i].aa,a[i].bb);
            maxa+=max(maxb,a[i].cc);
            maxb=0;
            if(a[i].aa==max(a[i].aa,a[i].bb)&&a[i].aa==max(a[i].aa,a[i].cc)){
                cnta++;
            }else if(a[i].bb==max(a[i].aa,a[i].bb)&&a[i].bb==max(a[i].bb,a[i].cc)){
                cntb++;
            }else{
                cntc++;
            }
            if(cnta>n/2){
                maxa-=a[i].aa;
                cnta--;
                maxa+=a[i].bb;
                cntb++;
            }if(cntb>n/2){
                maxa-=a[i].bb;
                cntb--;
                maxa+=a[i].cc;
                cntc++;
            }if(cntc>n/2){
                maxa-=a[i].cc;
                cntc--;
                maxa+=a[i].aa;
                cnta++;
            }if(cnta>n/2){
                maxa-=a[i].aa;
                cnta--;
                maxa+=a[i].bb;
                cntb++;
            }
        }


        maxab=max(maxab,maxa);
        cout<<maxab<<"\n";
        maxa=0;
    }
    return 0;
}
