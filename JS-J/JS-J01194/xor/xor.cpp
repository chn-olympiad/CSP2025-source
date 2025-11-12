#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;
const int N=5e5+5;
long long n,k,cnt;
long long t,b[N];
bool gg=1,ff=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>t;
        b[i]=b[i-1]^t;
        if(t!=1){
            gg=0;
            if(t!=0){
                ff=0;
            }
        }
    }
    if(gg){
        cout<<n/2;
        return 0;
    }
    else if(ff){
        if(k==0){
            for(int i=1;i<=n;){
                int t1=b[i-1]^b[i],t2=b[i]^b[i+1];
                if(t1==0){
                    cnt++;
                    i++;
                }
                else if(t2==1&&i+2<=n){
                    cnt++;
                    i+=2;
                }
                else{
                    i++;
                }
            }
        }
        else{
            for(int i=1;i<=n;i++){
                int t1=b[i-1]^b[i];
                if(t1==1){
                    cnt++;
                }
            }
        }
        cout<<cnt;
        return 0;
    }
    else{
        int oo=1;
        for(int i=1;i<=n;i++){
            for(int j=oo;j<=i;j++){
                t=b[i]^b[j-1];
                if(t==k){
                    cnt++;
                    oo=i+1;
                    break;
                }
            }
        }
        cout<<cnt;
        return 0;
    }
}
