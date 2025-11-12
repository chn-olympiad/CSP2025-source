#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    int a[500010];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    if(a[0]==k){
        sum++;
    }else if(a[1]==k){
        sum++;
    }
    if((a[0]^a[1])==k){
        sum++;
    }
    cout<<sum;
    return 0;
}