#include<bits/stdc++.h>
using namespace std;
int arr[105],brr[15][15];
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,ans;
    cin>>n>>m;
    int k=n*m;
    for(int i=1;i<=k;i++)cin>>arr[i];
    ans=arr[1];
    sort(arr,arr+k+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i%2)brr[i][j]=arr[k+1];
            else brr[i][m-j+1]=arr[k+1];
            if(arr[k--]==ans){
                if(i%2)cout<<i<<' '<<j;
                else cout<<i<<' '<<m-j+1;
                return 0;
            }
        }
    }
    return 0;
}
