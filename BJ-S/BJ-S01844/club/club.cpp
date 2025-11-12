#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+10;
int main(){
    int t,n,a,b,c,b1 = 0,b2 = 0,b3 = 0,ans = 0;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 1;i<=n;i++){
            cin>>a>>b>>c;
            int m = max(max(max(a,b),max(a,c)),max(b,c));
            if(m==a&&b1<(n/2)){
                b1++;
                ans+=m;
            }
            else if(m==b&&b2<(n/2)){
                b2++;
                ans+=m;
            }
            else if(m==c&&b3<(n/2)){
                b3++;
                ans+=m;
            }
            else if(b1==n/2){
                int m1 = max(b,c);
                if(m1==b){
                    b2++;
                    ans+=m1;
                }else{
                    b3++;
                    ans+=c;
                }
            }
            else if(b2==n/2){
                int m1 = max(a,c);
                if(m1==a){
                    b1++;
                    ans+=m1;
                }else{
                    b3++;
                    ans+=c;
                }
            }
            else if(b3==n/2){
                int m1 = max(a,b);
                if(m1==a){
                    b1++;
                    ans+=m1;
                }else{
                    b2++;
                    ans+=b;
                }
            }
        }
        cout<<ans<<endl;
        a=0,b=0,c=0,b1=0,b2=0,b3=0,ans = 0;
    }
    return 0;
}
