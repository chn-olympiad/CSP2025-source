#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int sum=0,lx=0,sum2=0,sum3=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            sum++;
            lx++;
        }else{
            sum2+=lx/2;
            lx=0;
        }
    }
    sum2+=lx/2;
    if(k==0){
        cout<<sum2+(n-sum);
    }else if(k==1){
        cout<<sum;
    }else{
        int sum3=0,yhh=0;
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                sum3++;
                yhh=0;
            }else{
                yhh^=a[i];
                if(yhh==k){
                    sum3++;
                    yhh=0;
                }
            }

        }
        cout<<sum3;
    }
    return 0;
}
