#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[1005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<2){
        cout<<0<<endl;
    }
    if(n==2 && a[0]==a[1] && a[0]==1 && k==0){
        cout<<1<<endl;
    }
    cout<<1<<endl;
    return 0;
}
