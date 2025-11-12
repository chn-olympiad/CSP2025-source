#ifndef POLYGON_CPP_INCLUDED
#define POLYGON_CPP_INCLUDED



#endif // POLYGON_CPP_INCLUDED

#include <bits/stdc++.h>
using namespace std;
long long n,a[5005];
long long b,f;
long long l,k;
long long c[1005][1005];
void cc(){
    for(int i=1;i<=1005;i++){
        c[i][i]=1;
        c[i][1]=i;
        for(int j=i-1;j>=2;j--){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            b++;
        }
        else{
            f=1;
        }
    }
    if(f==0){
        cout<<n-2;
    }
    else{
        sort(a+1,a+1+n);
        cc();
        for(int i=3;i<=n;i++){
            for(int j=1;j<=i-2;j++){
                k=j+1;
                while(j+k<=i){
                    k++;
                }
                for(int p=1;p<=i-k;p++){
                    l+=c[i-k][p];
                    l%=998244353;
                }
            }
        }
        cout<<l;
    }
    return 0;
}
