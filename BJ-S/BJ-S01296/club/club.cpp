#include<iostream>
#include<queue>
#include<algorithm>
#define maxn 100005
#define ll long long
using namespace std;
int T;
int n;
ll a1[maxn],a2[maxn],a3[maxn];
ll temp[maxn*2];

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        int a3_0=1,a2_0=1;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a1[i],&a2[i],&a3[i]);
            if(a3[i]!=0)a3_0=0;
            if(a2[i]!=0)a2_0=0;
        }
        ll ans=0;
        if(a3_0==1){
            if(a2_0==1){
                sort(a1+1,a1+n+1,greater<ll>());
                for(int i=1;i<=n/2;i++){
                    ans+=a1[i];
                }
                cout<<ans<<endl;
                return 0;
            }else{
                sort(a1+1,a1+n+1,greater<ll>());
                sort(a2+1,a2+n+1,greater<ll>());

            }
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
