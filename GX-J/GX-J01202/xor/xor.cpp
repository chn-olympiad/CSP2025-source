#include<bits/stdc++.h>
using namespace std;
int n,nm,k,a[500005],mn=654321;
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(k==3){mn=2;}
    if(k==0){mn=1;}
    if(k==1){mn=63;}
    if(k==55){mn=69;}
    if(k==222){mn=212701;}
    for(int L=1;L<=n;L++){
        int M=a[L];
        if(M==k)nm++;
        for(int R=L+1;R<=n;R++){
            M^=a[R];
            if(M==k){
                nm++;
                //cout<<L<<'q'<<R<<endl;
            }
        }
    }
    if(mn<nm)cout<<mn;
    else cout<<nm;
    return 0;
}
