#include<iostream>
#include<cstdio>
using namespace std;
int n,a[5005],maxn,s[5005];
long long ans;
const int M=998244353;

int mx(int l,int r){
    int maxm=-1;
    for(int i=l;i<=r;i++){
        maxm=max(maxm,a[i]);
    }
    return maxm;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        maxn=max(a[i],maxn);
    }
    if(n==3){
        if(a[1]+a[2]+a[3]>maxn*2)cout << 1;
        else cout << 0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        int sum=0;
        for(int j=i;j<=n;j++)sum+=a[j];
        s[i]=sum;
    }
    for(int m=3;m<=n;m++){
        for(int i=1;i<=n-m+1;i++){
            if(s[i]-s[i+m]>mx(i,i+m-1)*2)ans++;
        }
    }
    cout << ans;
    return 0;
}
