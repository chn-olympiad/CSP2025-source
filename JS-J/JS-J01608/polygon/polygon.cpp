#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a[5050],b[5050],cnt;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    if(a[0]+a[1]>a[2]||a[0]+a[2]>a[1]||a[2]+a[1]>a[0]){
        cout<<1;
        return 0;
    }
    else{
        cout<<0;
    }
    return 0;
}
