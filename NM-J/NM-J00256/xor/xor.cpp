#include<bits/stdc++.h>
using namespace std;
long long a[500010]={};
long long b[500010]={};
int k(long long x,long long y){
    for(long long i=x;i<=y;i++){
        if(b[i]==1){
            return 0;
        }
    }
    for(long long i=x;i<=y;i++){
        b[i]=1;
    }
    return 1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,x,nm=1,y;
    cin>>n>>x;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        y=a[i];
        for(long long j=i;j<=n;j++){
            if((y^(a[j]))==x&&k(i,j)){
                nm+=1;
                break;
            }
            else{
                y=(y^a[j]);
            }
        }
    }
    cout<<nm;
    return 0;
}
