#include<bits/stdc++.h>
using namespace std;
int n,k;
int sum=0;
int out=0;
int a[10010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]<=k){
                out=a[i];
            if(a[i]=k){
              sum=1;
            }else{
                for(int j=i;j<=n;j++){
                        out+=a[j];
                    if(out==k){
                        sum=j-i;
                        out=0;
                    }else if(out>k){
                        out=0;
                        break;
                    }
                }
            }
        }
    }
    cout<<sum;
}
