#include<bits/stdc++.h>
using namespace std;
int a[105];
bool check(int n,int t[]){
    for(int i=1; i<=n; i++){
        if(t[i]!=1) return false;
    }
    return true;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    
    int n,k,cnt=0;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    if(k==0) {
        if(check(n,a)){
            cout<<n/2;
        }
    }
    return 0;
}
// 1 3
// 10+40=50+200=250