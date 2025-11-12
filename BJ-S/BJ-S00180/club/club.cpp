#include<bits/stdc++.h>
using namespace std;
int T,n,cnt[4];
struct P{
    int st,nd,rd,num[4];
}a[200005];
bool cmp(P x,P y){
    int zx=0,zy=0;
    for(int i=1;i<=3;i++){if(x.num[i]==0)zx++;if(y.num[i]==0)zy++;}
    if(zx==zy)return x.num[1]+x.num[2]+x.num[3]>y.num[1]+y.num[2]+y.num[3];
    else return zx>zy;
}int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].num[1]>>a[i].num[2]>>a[i].num[3];
            int z=max(max(a[i].num[1],a[i].num[2]),a[i].num[3]);
            if(a[i].num[1]==z){
                a[i].st=1;
                if(a[i].num[2]>a[i].num[3]){a[i].nd=2;a[i].rd=3;}
                else a[i].nd=3;a[i].rd=2;
            }if(a[i].num[2]==z){
                a[i].st=2;
                if(a[i].num[1]>a[i].num[3]){a[i].nd=1;a[i].rd=3;}
                else a[i].nd=3;a[i].rd=1;
            }if(a[i].num[3]==z){
                a[i].st=3;
                if(a[i].num[1]>a[i].num[2]){a[i].nd=1;a[i].rd=2;}
                else a[i].nd=2;a[i].rd=1;
        }}sort(a+1,a+n+1,cmp);
        long long ans=0;
        cnt[1]=cnt[2]=cnt[3]=0;
        for(int i=1;i<=n;i++){
            if(cnt[a[i].st]<n/2){
                ans+=a[i].num[a[i].st];
                cnt[a[i].st]++;
            }else if(cnt[a[i].nd]<n/2){
                ans+=a[i].num[a[i].nd];
                cnt[a[i].nd]++;
            }else{
                ans+=a[i].num[a[i].rd];
                cnt[a[i].rd]++;
        }}cout<<ans<<"\n";
    }return 0;
}
