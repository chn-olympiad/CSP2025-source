#include <bits/stdc++.h>
using namespace std;
long long a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    long long n,ccnt=0;
    long long maxn;
    cin>>n;
    maxn=pow(2,n);
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=0;i<=maxn;i++){
        long long m=-1,kk=0,i1=i,cnt=0,k=0;
        while(i1!=0){
            k++;
            if(i1&1){
                if(a[k]>m){
                    m=a[k];
                }
                kk++;
                cnt+=a[k];
            }
            i1>>=1;
        }
        if(m*2<cnt&&kk>=3){
            ccnt++;
            ccnt%=998244353;
        }
    }
    cout<<ccnt;
    return 0;
}
