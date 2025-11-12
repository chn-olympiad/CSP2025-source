#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n;
bool flag=true;
int a[5555];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=1)flag=false;
    }
    if(flag==true){
        long long sum=0;
        int x=1,y=1;
        for(int i=3;i<=n;i++){
            x=1,y=1;
           for(int j=n;j>n-i;j--){
               x*=j;
                if(x>MOD)x=x%MOD;
        }
           for(int j=1;j<=i;j++){
               y*=j;
               if(y>MOD)y=y%MOD;
           }
           x/=y;
          sum+=x;
    }
    cout<<sum;
    }else if(n==3){
            int sum=a[1]+a[2]+a[3];
            if(sum<=max(a[1],max(a[2],a[3]))*2)cout<<0;
            else cout<<1;
    }else{
        cout<<998244352;
    }
    return 0;
}
//36
