#include <bits/stdc++.h>
using namespace std;
struct node{
    long long a,b,c;
}q[100005];
int T;
long long n,a[100005],b[100005],c[100005],ans,sp2a[100005],sp2b[100005],sp2al,sp2bl;
bool sp1=1,sp2=1;
bool cmp1(long long u,long long v){
    return u>v;
}
bool cmp2(node u,node v){
    return u.a>v.a;
}
bool cmp3(node u,node v){
    return u.b>v.b;
}
void dfs(long long p,long long num1,long long num2,long long num3,long long sum){
    if(num1>n/2||num2>n/2||num3>n/2){
        return;
    }
    if(p>n){
        ans=max(ans,sum);
        return;
    }
    dfs(p+1ll,num1+1ll,num2,num3,sum+a[p]);
    dfs(p+1ll,num1,num2+1ll,num3,sum+b[p]);
    dfs(p+1ll,num1,num2,num3+1ll,sum+c[p]);
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0ll,sp1=sp2=1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            q[i].a=a[i],q[i].b=b[i],q[i].c=c[i];
            if(a[i]<b[i]){
                sp2b[++sp2bl]=i;
            }
            else{
                sp2a[++sp2al]=i;
            }
            if(!(b[i]==0ll&&c[i]==0ll)){
                sp1=0;
            }
            if(c[i]!=0){
                sp2=0;
            }
        }
        if(sp1){
            sort(a+1,a+n+1,cmp1);
            for(int i=1;i<=n/2;i++){
                ans+=a[i];
            }
            cout<<ans<<endl;
            continue;
        }
        
        // if(sp2){
        //     long long ans1(0ll),ans2(0ll);
        //     sort(q+1,q+n+1,cmp2);
        //     for(int i=1;i<=n/2;i++){
        //         ans1+=q[i].a;
        //     }
        //     for(int i=n/2+1;i<=n;i++){
        //         ans1+=q[i].b;
        //     }
        //     sort(q+1,q+n+1,cmp3);
        //     for(int i=1;i<=n/2;i++){
        //         ans1+=q[i].b;
        //     }
        //     for(int i=n/2+1;i<=n;i++){
        //         ans1+=q[i].a;
        //     }
        //     cout<<max(ans1,ans2)/2<<endl;
        //     continue;
        // }

        // if(sp2){
        //     sort(sp2a+1,sp2a+sp2al+1,cmp1);
        //     sort(sp2b+1,sp2b+sp2bl+1,cmp1);
        //     if(sp2al>sp2bl){
        //         for(int i=1;i<=n/2;i++){
        //             ans+=a[sp2a[i]];
        //         }
        //         for(int i=n/2+1;i<=sp2al;i++){
        //             ans+=b[sp2a[i]];
        //         }
        //         for(int i=1;i<=sp2bl;i++){
        //             ans+=b[sp2b[i]];
        //         }
        //     }
        //     else{
        //         for(int i=1;i<=n/2;i++){
        //             ans+=b[sp2b[i]];
        //         }
        //         for(int i=n/2+1;i<=sp2bl;i++){
        //             ans+=a[sp2b[i]];
        //         }
        //         for(int i=1;i<=sp2al;i++){
        //             ans+=a[sp2a[i]];
        //         }
        //     }
        //     cout<<ans<<endl;
        //     continue;
        // }
        dfs(1ll,0ll,0ll,0ll,0ll);
        cout<<ans<<endl;
    }
    return 0;
}