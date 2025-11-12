#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,sum1,sum=0;
    cin>>n>>k;
    int a[500000]={};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int q,d;
    for(int i=0;i<n;i++){
        sum1=0;
        q=a[i];
        d=i+1;
        while(d<n){
            if(q==k){
                sum1++;
                q=a[d];
            }else{
                q=q^a[d];
            }
            d++;
        }
        if(q==k){
            sum1++;
        }
        if(sum1>sum){
            sum=sum1;
        }
    }

    cout<<sum;

    return 0;
}
