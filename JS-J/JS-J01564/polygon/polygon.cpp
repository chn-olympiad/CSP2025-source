#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const ll Mod=998244353;
int a[5003];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    if(n<=(ll)3){ //dabiao
        if(n==(ll)3){
            int a,b,c;
            cin>>a>>b>>c;
            if(a+b>c && a+c>b && b+c>a) cout<<1<<endl;
            else cout<<0<<endl;
            return 0;
        } else{
            cout<<0<<endl;
            return 0;
        }
    }

    //bool spcA=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //if(a[i]>1) spcA=0;
    }

    //if(spcA){
        int ans=0;
        for(int i=3;i<=n;i++){
            int sum=1;
            for(int j=0;j<i;j++){
                sum*=n-j;
                sum%=Mod;
            }
            for(int j=i;j>=1;j--){
                sum/=j;
            }
            ans+=sum;
            ans%=Mod;
        }
        cout<<ans%Mod<<endl;
        return 0;
    // }
    return 0;
}
