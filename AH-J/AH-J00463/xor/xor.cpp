#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[10005],b[10005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=0;
    }
    if(k==0){
        cout<<n;
    }
    if(k==1){
        int sum=0;
        for(int i=1;i<=n-1;i++){
            if(a[i]!=a[i+1] && b[i]!=1 && b[i+1]!=1){
                sum++;
                b[i]=1;
                b[i+1]=1;
            }
        }
        cout<<sum;
    }
    return 0;
}
