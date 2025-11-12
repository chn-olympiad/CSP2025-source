#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.ans", "w", stdout);
    int t,b=0;
    cin>>t;
    while (b!=t){
        int n,a[100007][7],z=0,y=0,ans=0;
        cin>>n;

        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]==0 and a[i][3]==0){
                z++;
            }
        }
        if(n==2){
            ans=max(ans,(a[1][1]+a[2][2]));
            ans=max(ans,(a[1][1]+a[2][3]));
            ans=max(ans,(a[1][2]+a[2][1]));
            ans=max(ans,(a[1][2]+a[2][3]));
            ans=max(ans,(a[1][3]+a[2][1]));
            ans=max(ans,(a[1][3]+a[2][2]));
            cout<<ans;
        }
        else{
            if(z==n){
                for(int i=1;i<n;i++){
                    for(int j=1;j<=n-i;j++){
                        if(a[j][1]<a[j+1][1]){
                            swap(a[j][1],a[j+1][1]);
                        }
                    }
                }
                for(int i=1;i<=n/2;i++){
                    ans=ans+a[i][1];
                }
                cout<<ans;
            }
        }
        b++;
    }
    return 0;
}
