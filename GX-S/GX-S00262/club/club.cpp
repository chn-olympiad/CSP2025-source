#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
struct ed{
    int x1,x2,x3;
};
ed a[30000];
int sum[45];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].x1>>a[i].x2>>a[i].x3;
            if(a[i].x1>a[i].x2&&a[i].x1>a[i].x3){
                if(sum[1]<n/2){
                    sum[1]++;
                    ans+=a[i].x1;continue;
                }
            }
            if(a[i].x2>a[i].x3&&a[i].x2>a[i].x1){
                if(sum[2]<n/2){
                    sum[2]++;
                    ans+=a[i].x2;continue;
                }
            }
            if(a[i].x3>a[i].x2&&a[i].x3>a[i].x1){
                if(sum[3]<n/2){
                    sum[3]++;
                    ans+=a[i].x3;continue;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
