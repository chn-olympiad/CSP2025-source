#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        scanf("%d",a[n]);
    }
    long long sum1=0,sum2=0,sum3=0;
    if(n>=3){
        int j,t;
        for(int i=0;i<=j;i++){
            for(int j=i;j<=t;j++){
                for(int t=j;t<n;t++){
                    if(a[i]<a[j]&&a[t]<a[j]){
                        if(a[i]+a[j]+a[t]>=2*a[j]){
                            sum1++;
                        }
                    }
                    if(a[j]<a[t]&&a[i]<a[t]){
                        if(a[i]+a[j]+a[t]>=2*a[t]){
                            sum2++;
                        }
                    }
                    if(a[t]<a[i]&&a[j]<a[i]){
                        if(a[i]+a[j]+a[t]>=2*a[i]){
                            sum3++;
                        }
                    }
                }
            }
        }
    }
    printf("%d",(sum1+sum2+sum3)%998244353);
    return 0;
}
