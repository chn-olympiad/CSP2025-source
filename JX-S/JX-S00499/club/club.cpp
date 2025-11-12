#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5+2;
ll t, n,a[N][10];
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ll ma=0,mb=0,mc=0,asum=0,bsum=0,csum=0;
    memset(a,0,sizeof(a));
    cin >> t;
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        reverse(a,a+1+n);
        for(int i=1;i<=n;i++){
            ma+=max(a[i][2],a[i][1]);
            mb+=max(max(a[i][2],a[i][1]),a[i][3]);
            mc+=max(max(a[i][2],a[i][1]),a[i][3]);

            if(a[i][1]==max(max(a[i][2],a[i][1]),a[i][3]))
                asum++;
            else if(a[i][2]==max(max(a[i][2],a[i][1]),a[i][3]))
                bsum++;
            else if(a[i][3]==max(max(a[i][2],a[i][1]),a[i][3]))
                csum++;
            if(asum>=n/2){
                ma-=a[i][1];
                asum--;
            }
            if(bsum>=n/2){
                mb-=a[i][1];
                bsum--;
            }
            if(csum>=n/2){
                mc-=a[i][1];
                csum--;
            }
        }
        printf("%lld\n",&ma);
    }

    return 0;
}
