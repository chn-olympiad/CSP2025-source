#include<iostream>
#include<unordered_map>
using namespace std;
long long n,k,a[500050];
long long ans=0;
long long qz[500050];
unordered_map<long long,long long> ma;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1; i<=n; i++){
        cin>>a[i];
    }
    for(long long i=1; i<=n; i++){
        qz[i]=qz[i-1]^a[i];
    }
    long long last=-1;
    for(long long i=1; i<=n; i++){
        long long x=qz[i];
        if((ma.count(x^k)==true&&ma[x^k]>=last)||(last==-1&&qz[i]==k)){
            last=i;
            ans++;
        }
        ma[qz[i]]=i;
    }
    cout<<ans;
    return 0;
}
