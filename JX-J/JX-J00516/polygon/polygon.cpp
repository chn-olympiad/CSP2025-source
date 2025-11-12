#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
long long n,a[N],f;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++) cin>>a[i];
    if(n==3){
        long long zd=0,s=0;
        for(long long i=0;i<n;i++){
            zd=max(zd,a[i]);
            s+=a[i];
        }
        if(s>(zd*2)) cout<<1;
        else cout<<0;
    }
    else{
        for(long long i=0;i<n;i++){
            for(long long j=i+1;j<n;j++){
                for(long long k=j+1;k<n;k++){
                    if(i!=j&&j!=k&&i!=k&&(a[i]+a[j]+a[k])>(max(a[i],max(a[j],a[k]))*2)) f++;
                    for(long long l=k+1;l<n;l++){
                        if(i!=j&&i!=k&&i!=l && j!=k&&j!=l && k!=l&&(a[i]+a[j]+a[k]+a[l])>(max(a[i],max(a[j],max(a[k],a[l])))*2)) f++;
                        for(long long m=l+1;m<n;m++){
                            if(i!=j&&i!=k&&i!=l&&i!=m && j!=k&&j!=l&&j!=m && k!=l&&k!=m && l!=m && (a[i]+a[j]+a[k]+a[l]+a[m])>(max(a[i],max(a[j],max(a[k],max(a[l],a[m]))))*2)) f++;
                        }
                    }
                }
            }
        }
        cout<<f;
    }
    return 0;
}
