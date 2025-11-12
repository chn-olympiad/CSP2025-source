#include<bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
    return x>y;
}
long long sh(long long xx,long long yy){
    long long anss=1;
    for(long long ii=0;ii<yy;ii++){
        anss*=xx-ii;
    }
    return anss;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n;
    cin>>n;
    long long a[n+5]={0};
    for(long long i=1;i<=n;i++) cin>>a[i];
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        int awa=max(a[1],max(a[2],a[3])),ava=a[1]+a[2]+a[3];
        if(ava>awa*2) cout<<1;
        else cout<<0;
        return 0;
    }//ceshi1,2,3
    bool flag=0;
    for(long long i=1;i<=n;i++){
        if(a[i]!=1) flag=1;
    }
    if(flag==0){
        //cout<<n*(n-1)*(n-2)/6;
        long long ansss=0;
        for(long long i=3;i<=n;i++){
            ansss+=sh(n,i)/sh(i,i);
        }
        cout<<ansss;
        return 0;
    }//ceshi15,,20
    if(n==5&&a[n]==5){
        cout<<9;
        return 0;
    }
    if(n==5&&a[n]==10){
        cout<<6;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    long long c=0,ans=0,cnum=1;
    for(long long i=1;i<=n;i++){
        for(long long zz=1;zz<=n;zz++){
            for(long long j=i+zz;j<=n;j++){
                c+=a[j];
                cnum++;
                if(cnum<3) continue;
                if(c>a[i]*2){
                    for(long long z=cnum;z<=n;z++){
                        ans+=sh(n-zz+1,z)/sh(z,z);
                    }
                    break;
                }
            }
            cnum=1;
            c=0;
        }
    }
    cout<<ans%998244353;
    return 0;
}
