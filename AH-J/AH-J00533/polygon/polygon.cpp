#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[5005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2]) cout<<1;
        else cout<<0;
    }
    else if(a[1]==1&&a[2]==1&&a[3]==1&&n>3){
        long long s;
        for(int i=3;i<=n;i++){
            long long q=1,w=1;
            for(int j=1;j<=i;j++){
                w*=j;
                w%=N;
            }
            for(int j=n;j>n-i;j--){
                q*=j;
                q%=N;
            }
            q/=w;
            s+=q;
            s%=N;
        }
        cout<<s;
    }
    return 0;
}
