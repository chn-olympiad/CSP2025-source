#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        int a,b,c;
        int asum=0,bsum=0,csum=0;
        int cnt=0;
        for(int j=1;j<=n;j++){
            cin>>a>>b>>c;
            if(a>=b&&a>=c&&asum+1<=n/2){
                asum++;
                cnt+=a;
            }else if(b>=a&&b>=c&&bsum+1<=n/2){
                bsum++;
                cnt+=b;
            }else if(c>=a&&c>=b&&csum+1<=n/2){
                csum++;
                cnt+=c;
            }
        }
        cout<<cnt<<endl;
    }
}
