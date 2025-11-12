#include <bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int ejz(int m){
    long long p=0,x=1;
    while(m!=0){
        if((m/2)%2==1){
            p*=x;
            x=1;
            p+=1;
            p*=10;
            m/=2;
        }else{
            m/=2;
            x*=10;
        }
    }
    return p;
}


int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    bool e=1;
    long long num=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1||a[i]==0){
                e=0;
        }
    }
    if(e!=1){
        for(int i=1;i<=n;i++){
            if(a[i]==k){
                num++;
            }
        }
    }
    cout<<num;
    return 0;
}
