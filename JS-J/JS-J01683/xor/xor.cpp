#include<bits/stdc++.h>
using namespace std;
const int N=500000+5;
int a[N],n,k,b[N],maxx=-1,t0=0,t1=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        a[i]=t;
        if(t==0){
            t0++;
        }if(t==1){
            t1++;
        }
    }
    if(k==0){
        cout<<t0<<endl;
    }if(k==1){
        cout<<t1<<endl;
    }
    return 0;
}
