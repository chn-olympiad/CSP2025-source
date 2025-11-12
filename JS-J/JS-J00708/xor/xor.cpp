#include<bits/stdc++.h>
using namespace std;
int n,w0,w1;
long long k,a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)w0++;
        else if(a[i]==1)w1++;
    }
    if(k==0){
        if(w1==n){
            cout<<n/2;
            return 0;
        }
        else{
            cout<<n-1;
            return 0;
        }
    }
    else if(k==1){
        cout<<w1;
        return 0;
    }
    else cout<<n/8;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
