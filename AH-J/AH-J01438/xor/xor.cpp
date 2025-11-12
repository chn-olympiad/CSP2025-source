#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    long long cnt=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=0;i<n;i++){
        for(long long j=1;j<=n;j++){
                long long h=a[j],t=0,b=0;
            for(long long k=j+1;k<=j+i;k++){
                    if(a[k]!=-1){
                       h=h^a[k];
                    }else{
                        b=1;
                    }
            }
            if(h==m&&j+i<=n&&b==0){
                for(long long k=j;k<=j+i;k++){
                    if(a[k]!=-1){
                        a[k]=-1;
                    }else{
                        t=1;
                        break;
                    }
                }
                if(t==0){
                    cout<<j<<" "<<j+i<<" ";
                    cnt++;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
