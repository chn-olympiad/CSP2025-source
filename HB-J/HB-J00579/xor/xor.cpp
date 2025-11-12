#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,sum=0,a[600000]={0};
    set<long long> s;
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){sum++;s.insert(i);}
    }
    for(long long i=1;i<n;i++){
        long long it=a[i];
        for(long long j=i+1;j<=n;j++){
            it=a[j]^it;
            if(it==k){
                bool flag=true;
                for(long long k=i;k<=j;k++){
                    if(s.count(k)==1){flag=false;}
                    s.insert(k);
                }
                if(flag) sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
