#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long num;
long long x(int i){
    if(i==3){
        return 1;
    }
    return i*x(i-1);
}
int main(){
    freopen(".in","r",stdin);
    freopen("number4.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    num=x(n);
    for(int i=2;i<n;i++){
        for(int j=0;j<i-1;j++){
            int l=0;
            for(int k=j;k<i;k++){
                l+=a[k];
            }
            if(l<a[i]){
                num-=x(i-j);
            }
        }
    }
    cout<<num%998244353;
}
