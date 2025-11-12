#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a[5005];
long long f[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1,x;i<=n;i++){
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int maxn=0;
        for(int j=i+2;j<=n;j++){
            maxn=max(a[i],maxn);
            if(f[j]-f[i-1]>2*maxn){
                cnt=(cnt+1)%998244353;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
}
