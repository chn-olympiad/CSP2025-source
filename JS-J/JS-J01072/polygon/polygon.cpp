#include <bits/stdc++.h>
using namespace std;
const int MAXN=998244353;
int n;
int a[5005];
int ans;
int cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        cnt+=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1; i<=n/2; i++) swap(a[i],a[n-i+1]);
    for(int i=1; i<=n; i++){
        cnt-=a[i];
        int m=cnt;
        int woh=0;
        for(int j=1; j<=n; j++){
            if(m>a[i]){
                woh++;
            }m-=a[j];
        }ans+=woh;
        ans%=MAXN;
        cnt+=a[i];
    }cout<<ans;
    return 0;
}
