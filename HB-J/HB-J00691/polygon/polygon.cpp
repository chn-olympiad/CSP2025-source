#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],ans;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]+a[k]>a[k]*2 and a[k]!=0){
                    ans++;
                }if(n>=4){
                    for(int l=k+1;l<n;l++){
                        if(a[i]+a[j]+a[k]+a[l]>a[l]*2 and a[k]!=0){
                            ans++;
                            if(n>=5){
                               for(int o=k+1;o<n;o++){
                                    if(a[i]+a[j]+a[k]+a[l]+a[o]>a[o]*2 &&a[o]!=0){
                                        ans++;
                                     if(n==6){
                                        for(int p=k+1;p<n;p++){
                                            if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]>a[p]*2 &&a[p]!=0){
                                        ans++;
                                     }
                            }
                    }
                }
            }
        }
    }}}}}}
    cout<<ans<<endl;
    return 0;
}
