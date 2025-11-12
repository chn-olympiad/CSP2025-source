#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int maxj=max(a[1],max(a[2],a[3]));
    if(n==3 && a[1]+a[2]+a[3]>maxj*2 && a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[3]+a[2]>a[1]){

    }
    long long h=0;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n;j++){
            int t=1;
            while(t<=n-i){
                if(i+j-t-1<=n){
                    long long maxi=-1;
                    long long s=0;
                    s+=a[i+j-t];
                    int k;
                    for(k=1;k<=i;k++){
                        if(a[k]!=a[i+j-t]){
                            s+=a[k];
                        }
                        if(a[k]>maxi){
                            maxi=a[k];
                        }
                    }
                    if(s>maxi*2){
                        h++;
                    }
                }
                h=h%998224353;
                t++;
            }
        }
    }
    cout<<h%998224353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
