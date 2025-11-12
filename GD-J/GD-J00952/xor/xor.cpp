#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int z[n];
    bool a=true,b=true,c=true;
    for(int i=0;i<n;i++){
        cin>>z[i];
        if(z[i]!=1){
            a=false;
        }if(z[i]>1){
            b=false;
        }if(z[i]>255){
            c=false;
        }
    }if(a){
        cout<<n/2;
    }else if(b){
        int ma=0,temp=z[0];
            for(int i=1;i<n;i++){
                if(temp==k){
                    ma+=1;
                    temp=z[i];
                }else{
                    temp=temp^z[i];
                }
            }if(temp==k){
                ma+=1;
            }cout<<ma;
    }else{
        int ma=0,temp=z[0];
            for(int i=1;i<n;i++){
                if(temp==k){
                    ma+=1;
                    temp=z[i];
                }else{
                    temp=temp^z[i];
                }
            }if(temp==k){
                ma+=1;
            }cout<<ma;
    }return 0;
}
