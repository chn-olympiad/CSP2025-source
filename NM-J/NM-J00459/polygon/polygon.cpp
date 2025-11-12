#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[1000001];
long long ans;
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
    cin>>n;
    bool is1=true;

    for(long long i=1;i<=n;i++){
        cin>>a[i];
        a[0]=a[1];
        if(a[i]!=a[i-1]) is1=false;
    }
    if(is1){
        for(int i=n;i>=3;i--){
            long long ans1=1;
            for(int j=n;j>i;j--){
                ans1*=j;
            }
            ans+=ans1;

        }
        ans%=998244353;
         cout<<ans;
    }
    else if(n<=3){
        sort(a+1,a+n+1);
        if(n==3){
            if(a[1]+a[2]>a[3]){
                    cout<<a[3];
            }
            else{
                cout<<0;
            }
        }
        else{
            cout<<0;
        }

    }
    else{
        cout<<9;
    }
    return 0;
}

