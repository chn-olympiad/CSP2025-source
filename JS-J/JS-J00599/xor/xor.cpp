#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500005],b;
    bool A=true,B=true;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            b++;
        }
        if(a[i]!=1){
            A=false;
            if(a[i]!=0){
                B=false;
            }
        }
    }
    if(A){
        cout<<n/2<<endl;
    }else if(B){
        if(k==1){
            cout<<b<<endl;
        }else{
            cout<<b/2<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
