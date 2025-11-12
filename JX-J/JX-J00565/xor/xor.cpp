#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005]={};
long long s;
long long b[500005][21]={};//Cun(2)Chu(3)Mei(3)Yi(2)Ge(4)Shu(4)2Jing(4)Zhi(4)
long long z[21]={};
int main(){
    freopen("xor.out","w",stdout);
    freopen("xor.in","r",stdin);
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long k0=k,i=1;
    while(k0>0){
        z[i]=k0%2;
        k0=k0/2;
        i++;
    }
    z[0]=i;
    for(long long i=1;i<=n;i++){
        long long a0=a[i];
        long long l=1;
        b[i][l]=a0%2;
        a0/=2;
        l++;
        while(a0>0){
            b[i][l]=a0%2;
            a0/=2;
            l++;
        }
        b[i][0]=l-1;
    }/*
    for(long long i=1;i<=n;i++){
       for(long long j=0;j<=b[i][0];j++){
           cout<<b[i][j]<<" ";
       }
       cout<<"\n";
    }*/
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
            bool awa=true;
            long long jg[21]={};
            for(long long m=max(b[i][0],b[j][0]);m>0;m--){
                jg[m]=b[i][m]^b[j][m];
            }
            for(long long m=max(z[0],max(b[i][0],b[j][0]));m>0;m--){
                if(z[m]!=jg[m]){
                    awa=false;
                }
            }
            s=s+awa;
        }
    }
    printf("%lld",s);
    fclose(stdout);
    fclose(stdin);
    return 0;
}
