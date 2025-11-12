#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=100010;
ll a[N][4];
int cnt1,cnt2,cnt3;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        ll ans=0;
        scanf("%d",&n);
        vector<ll> cm[4];
        cm[1].reserve(n+5);
        cm[2].reserve(n+5);
        cm[3].reserve(n+5);
        cnt1=cnt2=cnt3=0;

        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
            ll a1=a[i][1],a2=a[i][2],a3=a[i][3];
            if(a1>a2){
                if(a1>a3){
                    cnt1++;
                    ans+=a1;
                    cm[1].push_back(a1-max(a2,a3));
                }else{
                    cnt3++;
                    ans+=a3;
                    cm[3].push_back(a3-max(a1,a2));
                }
            }else{
                if(a2>a3){
                    cnt2++;
                    ans+=a2;
                    cm[2].push_back(a2-max(a1,a3));
                }else{
                    cnt3++;
                    ans+=a3;
                    cm[3].push_back(a3-max(a1,a2));
                }
            }
        }
        int z=n/2;
        if(cnt1>z){
            sort(cm[1].begin(),cm[1].end());
            for(int i=1;i<=cnt1-z;i++){
                ans-=cm[1][i-1];
            }
        }
        else if(cnt2>z){
            sort(cm[2].begin(),cm[2].end());
            for(int i=1;i<=cnt2-z;i++){
                ans-=cm[2][i-1];
            }
        }
        else if(cnt3>z){
            sort(cm[3].begin(),cm[3].end());
            for(int i=1;i<=cnt3-z;i++){
                ans-=cm[3][i-1];
            }
        }
        cout<<ans<<'\n';

    }
    return 0;
}
