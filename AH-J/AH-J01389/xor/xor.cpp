#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000000],myo,myz,myoo;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]){
            myo++;
            if(a[i-1]){
                myoo++;
                a[i]=0;
            }
        }
        else{
            myz++;
        }
    }
    if(k==1){
        cout<<myo;
    }
    else{
        cout<<myz+myoo;
    }
    return 0;
}
