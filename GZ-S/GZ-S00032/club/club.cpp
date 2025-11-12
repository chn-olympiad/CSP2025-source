//GZ-S00032 侯恩彤 贵阳市云岩区中天中学
#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
    int val,index;
};
int ans=0;
struct club{
    node d,d1,d2;
}a[100010];
bool cmp(club a,club b){
    return a.d.val>b.d.val;
}
bool cmp1(club a,club b){
    return a.d1.val>b.d1.val;
}
bool cmp2(club a,club b){
    return a.d2.val>b.d2.val;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        n=0;
        cin>>n;
        memset(a,0,sizeof(a));
        ans = 0;
        for(int i = 1;i <= n;i++){
            cin>>a[i].d.val>>a[i].d1.val>>a[i].d2.val;
            a[i].d.index=a[i].d1.index=a[i].d2.index=i;
        }
        sort(a+1,a+1+n,cmp);
        sort(a+1,a+1+n,cmp1);
        sort(a+1,a+1+n,cmp2);
        for(int i = 1;i <= n;i++){
            ans+=a[i].d.val;
            a[i].d.val = 0;
            for(int j = 1;j <= n;j++){
                if(a[j].d1.index==a[i].d.index){
                    a[j].d1.val=0;
                }
                if(a[j].d2.index==a[i].d.index){
                    a[j].d2.val=0;
                }
            }
            ans+=a[i].d1.val;
            for(int j = 1;j <= n;j++){
                if(a[j].d.index==a[i].d1.index){
                    a[j].d.val = 0;
                }
                if(a[j].d2.index==a[i].d1.index){
                    a[j].d2.val = 0;
                }
            }
            ans+=a[i].d2.val;
            for(int j = 1;j <= n;j++){
                if(a[j].d.index==a[i].d2.index){
                    a[j].d.val=0;
                }
                if(a[j].d1.index==a[i].d2.index){
                    a[j].d1.val = 0;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
