#include<bits/stdc++.h>
using namespace std;
int n,m,s[200];
int main(){
    freopen(seat.in,'r',in);
    freopen(seat.out,'w',out);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>s[i];
    }
    int ans=s[0];
    sort(s,s+n*m);
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                if(s[i*m-m+j]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }else if(i%2==0){
            for(int j=m;j>=1;j--){
                if(s[i*m-m+j]==ans){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}