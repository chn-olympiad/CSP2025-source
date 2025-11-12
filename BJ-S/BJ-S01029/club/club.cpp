#include<bits/stdc++.h>
using namespace std;
struct myd{
    int a,b,c;
}a[100010];
bool cmp(myd a,myd b){
    int ma1=max(a.a,max(a.b,a.c));
    int mi1=min(a.a,min(a.b,a.c));
    int mid1=a.a+a.b+a.c-ma1-mi1;
    int ma2=max(b.a,max(b.b,b.c));
    int mi2=min(b.a,min(b.b,b.c));
    int mid2=b.a+b.b+b.c-ma1-mi1;
    return ma1-mid1>ma2-mid2;
}
int main(){ 
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n,cnt[4],ans=0;
        for(int i=1;i<=3;i++)
            cnt[i]=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i].a>>a[i].b>>a[i].c;
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            int ma=1,mid=2,mi=3;
            if(a[i].a<a[i].b) swap(ma,mid);
            if(a[i].a<a[i].c) swap(ma,mi);
            if(a[i].b<a[i].c) swap(mid,mi);
            if(cnt[ma]<n/2){
                if(ma==1) ans+=a[i].a;
                if(ma==2) ans+=a[i].b;
                if(ma==3) ans+=a[i].c;
                cnt[ma]++;
            }else if(cnt[mid]<n/2){
                if(mid==1) ans+=a[i].a;
                if(mid==2) ans+=a[i].b;
                if(mid==3) ans+=a[i].c;
                cnt[mid]++;
            }else{
                if(mi==1) ans+=a[i].a;
                if(mi==2) ans+=a[i].b;
                if(mi==3) ans+=a[i].c;
                cnt[mi]++;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}
