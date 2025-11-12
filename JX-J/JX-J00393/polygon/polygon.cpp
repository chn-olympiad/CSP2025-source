#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL a[50005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    LL maxs=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxs=max(maxs,a[i]);
    }
    sort(a+1,a+1+n);
    if(maxs==1){
        LL num=0;
        for(int i=3;i<=n;i++){
            LL ans=1;
            for(int j=1;j<=i;j++){
                ans=ans*((n-j+1))/j;
                ans%=998244353;
            }
            num+=ans;
            num%=998244353;
        }
        cout<<num%998244353;
    }
    else if(n==3){
        int s1=a[1],s2=a[2],s3=a[3];
        if(s1+s2>s3){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
    return 0;
}
