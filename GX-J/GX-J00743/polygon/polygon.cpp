#include<bits/stdc++.h>
using namespace std;
int a[5001][5001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[1][i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>1;i--){
        for(int j=1;j<n-i+1;j++){
            a[i][j]=a[1][j]+a[1][i+j-1];
        }
    }
    int ans=0;
    for(int i=2;i<=n;i++){
        for(int j=n-i+1;j>0;j--){
            for(int k=j+i;k<=n;k++){
                if(a[i][j]>a[1][k])
                    ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
