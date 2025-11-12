#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,ans;
    cin>>n>>m;
    int sum=m*n;
    int a[sum+5],s[n+5][m+5];
    for(int i=1;i<=sum;i++){
        cin>>a[i];
    }
    ans=a[1];
    for(int i=1;i<=sum;i++){
        for(int j=i;j<=sum;j++){
            if(a[j]>a[i]) swap(a[i],a[j]);
        }
    }
    int q=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(a[q]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }
                s[j][i]=a[q];
                q++;
            }
        }else{
            for(int j=n;j>=1;j--){
                if(a[q]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }
                s[j][i]=a[q];
                q++;
            }
        }
    }
    return 0;
}
