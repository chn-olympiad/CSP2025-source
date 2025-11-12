#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100005][5],ans=0,k1=0,k2=0,k3=0,id;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--){
        priority_queue<long long,vector<long long>,greater<long long> >q;
        scanf("%lld",&n);
        ans=k1=k2=k3=0;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
                k1++;
                ans+=a[i][1];
                continue;
            }
            if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
                k2++;
                ans+=a[i][2];
                continue;
            }
            if(a[i][3]>=a[i][1] && a[i][3]>=a[i][2]){
                k3++;
                ans+=a[i][3];
                continue;
            }
        }
        if(k1<=n/2 && k2<=n/2 && k3<=n/2){
            printf("%lld\n",ans);
            continue;
        }
        if(k1>n/2) id=1;
        if(k2>n/2) id=2;
        if(k3>n/2) id=3;
        for(int i=1;i<=n;i++){
            if(a[i][id]>=a[i][1] && a[i][id]>=a[i][2] && a[i][id]>=a[i][3]){
                if(id==1){
                    q.push(min(a[i][id]-a[i][2],a[i][id]-a[i][3]));
                }
                if(id==2){
                    q.push(min(a[i][id]-a[i][1],a[i][id]-a[i][3]));
                }
                if(id==3){
                    q.push(min(a[i][id]-a[i][1],a[i][id]-a[i][2]));
                }
            }
        }
        while(q.size()>n/2){
            ans-=q.top();
            q.pop();
        }
        printf("%lld\n",ans);
    }
    return 0;
}
