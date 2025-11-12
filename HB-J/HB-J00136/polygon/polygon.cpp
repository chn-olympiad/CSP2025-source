#include<bits/stdc++.h>
using namespace std;
long long a[50010],b[50010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n,p=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p+=a[i];
    }
    sort(a+1,a+1+n);
    if(n<=3){
        if((a[1]+a[2])>a[3]){
            cout<<1;
            return 0;
        }
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        b[i]=a[i]+b[i-1];
    }
    long long o=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i-2;j++){
            int u=p-(b[i]-b[j-1]);
            if(i!=n){
                if(u>n*2){
                    o++;
                    o%=998244353;
                }
            }else{
                if(u>(j-1)*2){
                    o++;
                    o%=998244353;
                }
            }
        }
    }
    cout<<o;
    return 0;
}
