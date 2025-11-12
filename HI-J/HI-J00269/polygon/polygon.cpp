#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int a[N],mn[N],n;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=2;i<=n;i++) mn[i]=min(a[i],a[i-1]);
    sort(a+1,a+n+1);
    long long ans=0;
    for(int i=3;i<=n;i++){
        int t=a[i];
        for(int j=i-1;j>1;j--){
            if(mn[j]>t){
                ans+=j*(j-1);
                break;
            }
            t-=a[j];
        }
    }
    cout << ans;
    return 0;
}
