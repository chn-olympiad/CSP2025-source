#include<bits/stdc++.h>
using namespace std;
int n,s[300010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int ans=0,ac=0,bc=0,cc=0;
        cin>>n;
        if(n==2){
            int a1,b1,c1,a2,b2,c2,cnt=0;
            cin>>a1>>b1>>c1>>a2>>b2>>c2;
            s[1]=a1+b2;
            s[2]=a1+c2;
            s[3]=b1+a2;
            s[4]=b1+c2;
            s[5]=c1+a2;
            s[6]=c1+b2;
            for(int i=1;i<=16;i++){
                cnt=max(cnt,s[i]);
            }
            cout<<cnt<<"\n";
        }else{
            for(int i=1;i<=n;i++){
                int a,b,c;
                cin>>a>>b>>c;
                if((a>=c&&a>=b&&ac<n/2)||(cc>=n/2&&a>b&&ac<n/2)||(bc>n/2&&a>c&&ac<n/2)){
                    ans+=a;
                    ac++;
                }else if((b>=a&&b>=c&&bc<n/2)||(ac>=n/2&&b>c&&bc<n/2)||(cc>n/2&&b>a&&bc<n/2)){
                    ans+=b;
                    bc++;
                }else if((c>=a&&c>=b&&cc<n/2)||(ac>=n/2&&c>b&&cc<n/2)||(bc>n/2&&c>a&&cc<n/2)){
                    ans+=c;
                    cc++;
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
