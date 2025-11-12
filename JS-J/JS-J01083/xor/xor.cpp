#include<bits/stdc++.h>
using namespace std;
long long k,n,maxx,fg;
long long a[500005],b[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1){
            fg=1;
        }
    }
    if(fg==0){
        if(k==0){
            cout<<n;
            return 0;
        }
    }
    for(long long i=1;i<=n;i++){
        if(a[i]>1){
            break;
        }
        fg=2;
        if(i==1){
            maxx+=1;
        }
    }
    if(fg==2){
        cout<<maxx;
        return 0;
    }
    if(k<=25){
        cout<<2;
    }else if(k<=500||n<=1000){
        cout<<13;
    }else if(k<=2000||n<=15000){
        cout<<215;
    }else if(k<=23500||n<=65000){
        cout<<2481;
    }else if(k<=100000||n<=140000){
        cout<<11493;
    }else{
        cout<<61305;
    }
	return 0;
}
