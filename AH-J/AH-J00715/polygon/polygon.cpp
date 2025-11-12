#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int maxn=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                maxn=max(max(a[i],a[j]),a[k]);
                if(a[i]+a[j]+a[k]>2*maxn) cnt++;
                for(int i2=k+1;i2<=n;i2++){
                     maxn=max(max(a[i],a[j]),max(a[i2],a[k]));
                    if(a[i]+a[j]+a[k]+a[i2]>2*maxn) cnt++;
                    for(int j2=i2+1;j2<=n;j2++){
                        maxn=max(max(max(a[i],a[j]),max(a[i2],a[k])),a[j2]);
                        if(a[i]+a[j]+a[k]+a[i2]+a[j2]>2*maxn) cnt++;
                        for(int k2=j2+1;k2<=n;k2++){
                            maxn=max(max(max(a[i],a[j]),max(a[i2],a[k])),max(a[j2],a[k2]));
                            if(a[i]+a[j]+a[k]+a[i2]+a[j2]+a[k2]>2*maxn) cnt++;
                            for(int k3=k2+1;k3<=n;k3++){
                                maxn=max(max(max(a[i],a[j]),max(a[i2],a[k])),max(max(a[j2],a[k2]),a[k3]));
                                if(a[i]+a[j]+a[k]+a[i2]+a[j2]+a[k2]+a[k3]>2*maxn) cnt++;
                                for(int k4=k3+1;k4<=n;k4++){
                                    maxn=max(max(max(a[i],a[j]),max(a[i2],a[k])),max(max(a[j2],a[k2]),max(a[k3],a[k4])));
                                    if(a[i]+a[j]+a[k]+a[i2]+a[j2]+a[k2]+a[k3]+a[k4]>2*maxn) cnt++;
                                    for(int k5=k4+1;k5<=n;k5++){
                                        maxn=max(max(max(a[i],a[j]),max(a[i2],a[k])),max(max(a[j2],a[k2]),max(a[k3],a[k4])));
                                        maxn=max(maxn,a[k5]);
                                        if(a[i]+a[j]+a[k]+a[i2]+a[j2]+a[k2]+a[k3]+a[k4]+a[k5]>2*maxn) cnt++;
                                        for(int k6=k5+1;k6<=n;k6++){
                                            maxn=max(max(max(a[i],a[j]),max(a[i2],a[k])),max(max(a[j2],a[k2]),max(a[k3],a[k4])));
                                            maxn=max(maxn,a[k5]);
                                            maxn=max(maxn,a[k6]);
                                            if(a[i]+a[j]+a[k]+a[i2]+a[j2]+a[k2]+a[k3]+a[k4]+a[k5]+a[k6]>2*maxn) cnt++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<cnt%998244353;
    return 0;
}
