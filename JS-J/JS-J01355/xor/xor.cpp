#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int n;
long long k;

long long xor1(long long a,long long b){
    long long d=0;
    int cnt=1;
    while(a||b){
        d+=((a%2)^(b%2))*cnt;
        a/=2;b/=2;
        cnt++;
    }
    return d;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long tmp;
        cin>>tmp;
        a[i]=xor1(tmp,a[i-1]);
        b[i]=tmp;
    }
    //for(int i=1;i<=n;i++){
     //   cout<<a[i];
    //}
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i==j){
                if(b[i]==k){
                    ans++;
                    break;
                }
            }
            else{
                if(xor1(a[i],a[j])==k){
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<n/2;
    return 0;
}
