#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,n1=0;
    cin>>n>>k;
    vector<long long>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<long long>b(n,0);
    b[0]=a[0];
    int z=0;
    for(int i=1;i<n;i++){
        b[i]=(b[i-1]^a[i]);
    }
    for(int i=0;i<n;i++){
        bool b1=0;
        for(int j=n1;j<=i;j++){
            if(j!=0){
            if((b[j-1]^b[i])==k){
                n1=i+1;
                b1=1;
            }
            }
            else{
            if(b[i]==k){
                n1=i+1;
                b1=1;
            }
            }
        }
        z+=b1;
    }
    cout<<z;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
