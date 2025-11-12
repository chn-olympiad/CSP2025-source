#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(n==3){
        if(a[1]+a[2]+a[3]>a[3]*2){
            ans++;
        }
        cout<<ans;
        return 0;
    }else{
        for(int i=3;i<=n;i++){
            int cnt=0;
            int r=i,l=1;
            while(r<=n){
                cnt=0;
                for(int j=l;j<=r;j++){
                    cnt+=a[j];
                }
                if(cnt>a[r]*2){
                    ans++;
                }
                r++;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}








