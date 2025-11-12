#include <bits/stdc++.h>
using namespace std;
int n,k;
int s;
int f0,f1;
int a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0) f0++;
        if(a[i]==1) f1++;
    }
    if(k==0){
        cout<<f0;
    }else{
        cout<<f1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
