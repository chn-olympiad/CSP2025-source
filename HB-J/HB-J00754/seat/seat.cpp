#include<bits/stdc++.h>
using namespace std;
int m,n,a[100000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int l=1,x=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int ans=a[1];
    sort(a,a+(n*m)+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==ans){
            ans=(n*m)-i;
        }
    }
    cout<<ans<<" ";
    if(ans==0){
        cout<<x<<" "<<l;
    }
    if(l==1&&ans>0){
        for(int i=1;i<=n;i++){
            if(l==n) break;
            ans--;
            l++;
            if(ans==0){
                cout<<x<<" "<<l;
            }
        }
    }
    if(l==n&&ans>0){
        x++;
        for(int i=1;i<=n;i++){
            ans--;
            if(ans==0){
                cout<<x<<" "<<l;
            }
            l--;
        }
    }

    return 0;
}
