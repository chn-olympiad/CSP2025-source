#include<bits/stdc++.h>
using namespace std;
int n,k,a[1000000],num,sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>num;
        a[i]=(a[i-1]^num);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[j+i-1]^a[j-1]==k){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
