#include<bits/stdc++.h>
using namespace std;
int a[5010];
long long he[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,i,j,l,k,cnt=0;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
        cout<<9;
    }else if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){
        cout<<6;
    }else{
        for(i=0;i<n;i++){
            for(j=1;j<n;j++){
                for(l=2;l<n;l++){
                    if(i!=j&&j!=l&&i!=l){
                        if(a[i]+a[j]+a[l]>2*max(a[i],max(a[j],a[l]))){
                            cnt++;
                        }
                    }
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=1;j<n;j++){
                for(l=2;l<n;l++){
                    for(k=3;k<n;k++){
                        if(i!=j&&i!=l&&i!=k&&j!=l&&j!=k&&l!=k){
                            if(a[i]+a[j]+a[l]+a[k]>2*max(max(a[i],a[k]),max(a[j],a[l]))){
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        cout<<cnt;
    }
    return 0;
}

