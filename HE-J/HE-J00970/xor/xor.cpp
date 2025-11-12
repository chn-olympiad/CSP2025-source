#include<iostream>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500001],g0=0,g1=0,S=0;
    bool A=1,B=1;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(a[i]==k){
            ++S;
        }
        if(a[i]!=1){
            A=0;
            if(a[i]!=0){
                B=0;
            }else{
                ++g0;
            }
        }else{
            ++g1;
        }
    }
    if(A){
        cout<<n/2;
    }else if(B){
        int s=0;
        if(k==0){
            s=g0;
            for(int i=0;i<n-1;++i){
                if(a[i]==1&&a[i+1]==1){
                    s++;
                    i++;
                }
            }
        }else{
            s=g1;
        }
        cout<<s;
    }else{
        cout<<S;
    }
    return 0;
}
