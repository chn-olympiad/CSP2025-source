#include<bits/stdc++.h>
using namespace std;
ifstream fin("polygon.in");
ofstream fout("polygon.out");
long long n;
long long a[5555];
const long long mod=998244353;
long long kuai_su_mi(long long n){
    long long an=1;
    for(int i=0;i<n;i++){
        an*=2;
        an=an%mod;
    }
    return an;
}
long long solve(long long m,long long maxn,long long maxsum,long long stick){
    if(m==n){
        if(stick>=3 and maxsum>2*maxn){
            return 1;
        }
        else{
            return 0;
        }
    }
    return solve(m+1,max(maxn,a[m]),maxsum+a[m],stick+1)%mod+solve(m+1,maxn,maxsum,stick)%mod;
}
int main(){
    fin>>n;
    bool flag=true;
    for(int i=0;i<n;i++){
        fin>>a[i];
        if(a[i]!=1){
            flag=false;
        }
    }
    if(flag){
        long long ans=kuai_su_mi(n);
        ans=ans+mod;
        ans=ans-1-n-n*(n-1)/2;
        ans=ans%mod;
        fout<<ans;
        return 0;
    }
    else{
        fout<<solve(0,0,0,0);
    }
}
