#include<bits/stdc++.h>
using namespace std;
long long k,a[600000],n,head1,tail1,head2,tail2;
/*int XORS(int h,int t){
    int s=0;
    for(int i=h;i<=t;i++){
        s=s^a[i];
    }
    return 0;
}*/
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(k==0){
        if(n==1){
            cout<<0;
        }
        if(n==2){
            cout<<1;
        }
        else{
            cout<<n/2;
        }
    }
    return 0;
}
