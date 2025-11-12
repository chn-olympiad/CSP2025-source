#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m,a[5000],sum=0,sum1=0,a_max=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=n){
           sum+=n;
        }
    }
    for(int m=3;m<=n;m++){
        for(int i=1;i<=m;i++){
            sum1+=a[i];
            if(a[i]>a_max){
                a_max=a[i];
            }
        }
        if(sum1<=2*a_max){
            sum--;
        }
    }
    cout<<sum;
    return 0;
}

