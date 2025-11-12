#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long T,n,a[100001][4],dp[100001],b[100001];
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            b[i]=a[i][0];
        }
        sort(b+1,b+n+1);
        int k;
        k=0;
        for(int i=n-n/2+1;i<=n;i++){
            k+=b[i];
        }
        cout<<k<<endl;
    }
    return 0;
}