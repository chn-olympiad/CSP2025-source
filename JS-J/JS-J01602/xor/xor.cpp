#include<bits/stdc++.h>
using namespace std;
const int N=100000000;
int a[N+1],n,k,b[N+1]={0},c[N+1]={0},ans=-1,sum;
int xorsolve(int m,int n){
    int maxn=max(m,n),ans=0,num,p;
    for(num=0,p=1;p<maxn;num++){
        p=p*2;
    }
    for(int i=num;i>0;i--){
        b[i]=m%2;
        m/=2;
    }
    for(int i=num;i>0;i--){
        c[i]=n%2;
        n/=2;
    }
    for(int i=num;i>0;i--){
        if(b[i]!=c[i]){
            int p=1;
            for(int j=0;j<num-i;j++) p*=2;
            ans+=p;
        }
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    if(k=0){
        cout<<n/2;
        return 0;
    }
    sum=a[0];
    for(int i=0;i<n;i++){
        if(sum!=k){
            ans++;
            sum=a[i];
            continue;
        }
        sum=xorsolve(a[i],sum);
    }
    cout<<ans;
    return 0;
}
