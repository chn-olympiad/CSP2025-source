#include<bits/stdc++.h>
using namespace std;
int lzm(int n){
    int a[n][3],ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
        }
    }int b[6]={a[0][0]+a[1][1],a[0][0]+a[1][2],a[0][1]+a[1][0],a[0][1]+a[1][2],a[0][2]+a[1][0],a[0][2]+a[1][1]};
    sort(b,b+6);
    ans=b[5];
    cout<<ans<<endl;
    return ans;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t,n;
cin>>t;
while(t>0){
    cin>>n;
    lzm(n);
    t--;
}
return 0;}
