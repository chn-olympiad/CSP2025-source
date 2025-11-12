#include<bits/stdc++.h>
using namespace std;
int t,maxn,n,a[3],k=0;
int main(){
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[0]>>a[1]>>a[2];
            for(int i=1;i<=3;i++){
                if(a[i+1]>=a[i])
                    maxn=a[i+1];
            }
            for(int j=1;j<=3;j++){
                k+=maxn;
            }
            k=0;
        }
    }
    for(int j=1;j<=t;j++){
        cout<<k;
    }
}
