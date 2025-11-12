#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int sum=0,l;
int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            sum++;
        }
        if(a[i]==0){
            l++;
        }
    }
    if(k==0){
        cout<<min(sum,l);
    }else{
        cout<<sum;
    }

    return 0;
}
