#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,s=0;
    long long sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    int f=s;
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--){
            s=f;
        for(int j=1;j<=i;j++){
            if(i-j<2) break;
            if(s>a[i]*2) sum++;
            s-=a[j];
            if(s<a[i]*2) break;
        }
        f-=a[i];
    }
    cout<<sum%998244353;

    return 0;
    }
