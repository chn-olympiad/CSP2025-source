#include<bits/stdc++.h>
#define f first.first
#define s first.second
#define t second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX=1e5+10,mod=1e9+7;
int t,n;
pair<pii,int> a[MAX];
ll sum[4]={0};
ll Max=0,ans=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i].f,&a[i].s,&a[i].t);}
        
        sort(a+1,a+1+n,[](pair<pii,int> a,pair<pii,int> b){
            return a.f>b.f;
        });
        for(int i=1;i<=n/2;i++){sum[1]+=a[i].f;}
        sort(a+1,a+1+n,[](pair<pii,int> a,pair<pii,int> b){
            return a.s>b.s;
        });
        for(int i=1;i<=n/2;i++){sum[2]+=a[i].s;}
        sort(a+1,a+1+n,[](pair<pii,int> a,pair<pii,int> b){
            return a.t>b.t;
        });
        for(int i=1;i<=n/2;i++){sum[3]+=a[i].t;}

        Max=max({sum[1],sum[2],sum[3]});
        if(Max==sum[1]){ans=Max+max(sum[2],sum[3]);}
        if(Max==sum[2]){ans=Max+max(sum[1],sum[3]);}
        if(Max==sum[3]){ans=Max+max(sum[1],sum[2]);}

        printf("%lld\n",ans);
    }
    return 0;
}