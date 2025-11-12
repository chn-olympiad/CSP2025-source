#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int n,a,b,c;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
             cin>>a>>b>>c;
        }
    }
    int cnt=0;
    int ans=0;
    int e=0;
    int zns=0;
    int za=0,zb=0,zc=0;
    int zo=0,zi=0;
    for(int i=0;i<t;i++){
        //ee=0;
        zo=0;
        for(int j=0;j<=n;j++){
           // cnt=0;
           // ans=0;
            //e=0;
            cnt=max(a,b);
            e=max(b,c);
            ans=max(cnt,e);
            //zns=min(cnt,e);
            //if(ans==a){
            //    za++;
            //}else if(ans==b){
            //    zb++;
            //}else if(ans==c){
           //     zc++;
            //}
            //if(za<=n/2&&zb<=n/2&&zc<=n/2){
            //    zo+=ans;
            //}else {
             //   zi+=zns;
           // }
           //zo+=ans;

        }
        //if(za<=n/2&&zb<=n/2&&zc<=n/2){
          //      cout<<zo<<endl;
          //  }else{
          //      cout<<zi<<endl;
           // }
           cout<<ans<<endl;
           ans=0;

    }

    return 0;
}
