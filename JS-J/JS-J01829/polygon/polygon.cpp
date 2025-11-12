#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5000],b[5000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s=0;
    sort(a,a+n,greater<int>());
    b[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        b[i]=a[i]+b[i+1];
    }
    for(int i=0;i<=n-3;i++){
        int j;
        int t=0;
        for(j=i+2;j<n;j++){
            if(b[i+1]-b[j]>a[i]){
                t=1;
                break;
            }
        }
        if(t==0)continue;
        int s2=1;
        for(int k=j;k<n;k++){
            s2*=2;
            s2%=mod;
        }
        for(int k=i+1;k<=j;k++){
            if(b[j+1]>a[k])s2*=2;
            s2%=mod;
        }
        s+=s2;
        s%=mod;
    }
    cout<<s;
    return 0;
}
