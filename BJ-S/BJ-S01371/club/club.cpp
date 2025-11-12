#include<bits/stdc++.h>
using LL=long long;
using namespace std;
const int N=1e5+5;
int n;
LL a[N],b[N],c[N],cha[N],tp[4],t[N];
void Main(){
    scanf("%d",&n);
    tp[1]=0;
    tp[2]=0;
    tp[3]=0;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",a+i,b+i,c+i);
        if(a[i]>=b[i]&&b[i]>=c[i]){
            tp[1]++;
            t[i]=1;
            cha[i]=a[i]-b[i];
        }
        else if(a[i]>=c[i]&&c[i]>=b[i]){
            tp[1]++;
            t[i]=1;
            cha[i]=a[i]-c[i];
        }
        else if(b[i]>=c[i]&&c[i]>=a[i]){
            tp[2]++;
            t[i]=2;
            cha[i]=b[i]-c[i];
        }
        else if(b[i]>=a[i]&&a[i]>=c[i]){
            tp[2]++;
            t[i]=2;
            cha[i]=b[i]-a[i];
        }
        else if(c[i]>=a[i]&&a[i]>=b[i]){
            tp[3]++;
            t[i]=3;
            cha[i]=c[i]-a[i];
        }
        else if(c[i]>=b[i]&&b[i]>=a[i]){
            tp[3]++;
            t[i]=3;
            cha[i]=c[i]-b[i];
        }
    }
    if(tp[1]<=n/2&&tp[2]<=n/2&&tp[3]<=n/2){
        LL ans=0;
        for(int i=1;i<=n;i++){
            if(t[i]==1){
                ans+=a[i];
            }
            else if(t[i]==2){
                ans+=b[i];
            }
            else{
                ans+=c[i];
            }
        }
        printf("%lld\n",ans);
        return;
    }
    vector<LL>v;
    if(tp[1]>n/2){
        int need=tp[1]-n/2;
        LL ans=0;
        for(int i=1;i<=n;i++){
            if(t[i]==1){
                ans+=a[i];
            }
            else if(t[i]==2){
                ans+=b[i];
            }
            else{
                ans+=c[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(t[i]==1){
                v.push_back(cha[i]);
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<=need-1;i++){
            ans=ans-v[i];
        }
        printf("%lld\n",ans);
        return;
    }
    if(tp[2]>n/2){
        int need=tp[2]-n/2;
        LL ans=0;
        for(int i=1;i<=n;i++){
            if(t[i]==1){
                ans+=a[i];
            }
            else if(t[i]==2){
                ans+=b[i];
            }
            else{
                ans+=c[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(t[i]==2){
                v.push_back(cha[i]);
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<=need-1;i++){
            ans=ans-v[i];
        }
        printf("%lld\n",ans);
        return;
    }
    if(tp[3]>n/2){
        int need=tp[3]-n/2;
        LL ans=0;
        for(int i=1;i<=n;i++){
            if(t[i]==1){
                ans+=a[i];
            }
            else if(t[i]==2){
                ans+=b[i];
            }
            else{
                ans+=c[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(t[i]==3){
                v.push_back(cha[i]);
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<=need-1;i++){
            ans=ans-v[i];
        }
        printf("%lld\n",ans);
        return;
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){
        Main();
    }
    return 0;
}
