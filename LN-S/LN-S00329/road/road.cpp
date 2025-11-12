#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct rd{
    int fr,to;
    long long co;
};
struct cr{
    int to;
    long long co;
};
rd a[1000010];
long long hua[27];
rd nl[200010];
int cnt;
bool cmp(rd aaa,rd bbb){
    return aaa.co<bbb.co;
}
bool cmp1(cr aaa,cr bbb){
    return aaa.co<bbb.co;
}
int fa[10050];
void rest(){
    for(int i=1;i<=n+k;i++)fa[i]=i;
    return;
}
int fi(int aa){
    if(fa[fa[aa]]==fa[aa])return fa[aa];
    fa[aa]=fi(fa[aa]);
    return fa[aa];
}
void uni(int aa,int bb){
   // cout<<"bin "<<aa<<" "<<bb<<endl;
    aa=fi(aa);
    bb=fi(bb);
    if(aa!=bb){
        fa[aa]=bb;
    }
    return;
}
long long ans=1000000000000000ll;
bool ava[20];
void calc(int id){
    rest();
  //  cout<<"WORKON"<<id<<endl;
    long long no=0;
    int tar=n;
    for(int i=1;i<=k;i++){
        ava[i]=id&1;
        id>>=1;
        if(ava[i]){
            tar++;
           no+=hua[i];
        }
     //  cout<<ava[i]<<" ";
    }
    //cout<<endl;
    if(no>ans)return;
    int zi=1,pi=1,bu=1;
    while(bu<tar){//zi shi dao pi shi huaiqnade
     //      cout<<no<<' '<<bu<<' '<<pi<<" "<<zi<<endl;
        if(zi>m||(pi<=cnt&&nl[pi].co<a[zi].co)){
            if(ava[nl[pi].fr-n]==0){
                pi++;
                continue;
            }
            if(fi(nl[pi].fr)!=fi(nl[pi].to)){
                uni(nl[pi].fr,nl[pi].to);
                no+=nl[pi].co;
                pi++;
                bu++;
            }else pi++;
        }else{
            if(fi(a[zi].fr)!=fi(a[zi].to)){
                uni(a[zi].fr,a[zi].to);
                no+=a[zi].co;
                zi++;
                bu++;
            }else zi++;
        }
        if(no>=ans)return;
    }
  //  cout<<no<<endl;
    if(no<ans)ans=no;
    return;
}
int main(){
    freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
   // cout<<ans<<endl;
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].fr>>a[i].to>>a[i].co;
    }
    sort(a+1,a+1+m,cmp);
    /*
    for(int i=1;i<=k;i++){
        cin>>hua[i];
        for(int j=1;j<=n;j++){
            nl[i][j].to=j;
            cin>>nl[i][j].co;
        }
        sort(nl[i]+1,nl[i]+1+n,cmp1);
        for(int j=1;j<=n;j++){
            cout<<nl[i][j].to<<' '<<nl[i][j].co<<endl;
        }
    }
    */
    for(int i=1;i<=k;i++){
        cin>>hua[i];
        for(int j=1;j<=n;j++){
            cnt++;
            nl[cnt].fr=i+n;
            nl[cnt].to=j;
            cin>>nl[cnt].co;
        }
    }
    sort(nl+1,nl+1+cnt,cmp);
    int mx=pow(2,k)-1;
  //  calc(31);
    //cout<<ans;
   // return 0;
 //   cout<<ans;
    for(int i=0;i<=mx;i++){
        calc(i);
    }
    cout<<ans;
    return 0;
}
