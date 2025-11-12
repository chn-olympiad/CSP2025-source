#include<bits/stdc++.h>
using namespace std;
long long n,t,a[100005],b[100005],c[100005],d[100005],e[100001],k,ma,mb,mc,ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ma=0,mb=0,mc=0,ans=0,k=0;
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
        for(int i=1;i<=n;i++){
            ans+=max(a[i],max(b[i],c[i]));
            if(a[i]>b[i]){
                if(a[i]>c[i]){
                    ma++;
                    d[i]=1;
                }
                else {
                    mc++;
                    d[i]=3;
                }
            }
            else {
                if(b[i]>c[i]){
                    mb++;
                    d[i]=2;
                }
                else {
                    mc++;
                    d[i]=3;
                }
            }
        }
        if(ma>n/2){
            for(int i=1;i<=n;i++){
                if(d[i]==1){
                    e[k]=min(a[i]-b[i],a[i]-c[i]);
                    k++;
                }
            }
            sort(e,e+k);
            for(int i=0;i<ma-n/2;i++){
                ans-=e[i];
            }
        }
        if(mb>n/2){
            for(int i=1;i<=n;i++){
                if(d[i]==2){
                    e[k]=min(b[i]-a[i],b[i]-c[i]);
                    k++;
                }
            }
            sort(e,e+k);
            for(int i=0;i<mb-n/2;i++){
                ans-=e[i];
            }
        }
        if(mc>n/2){
            for(int i=1;i<=n;i++){
                if(d[i]==3){
                    e[k]=min(c[i]-b[i],c[i]-a[i]);
                    k++;
                }
            }
            sort(e,e+k);
            for(int i=0;i<mc-n/2;i++){
                ans-=e[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
