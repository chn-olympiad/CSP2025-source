#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int as[5005];
long long aws;
void add(int m){
    as[1]++;
    for(int i=1;i<=m;i++){
        if(as[i]>=2){as[i+1]++;as[i]=0;}
    }
}
bool ant(void){
    long long sumn=0,maxn=0;
    for(int i=1;i<=n;i++){
        if(as[i]){sumn+=a[i];if(a[i]>=maxn)maxn=a[i];}
    }
    return sumn>2*maxn;
}
int sum(void){
    int s;
    for(int i=1;i<=n;i++)s+=as[i];
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<n;
    sort(a,a+n+1);
    for(int i=1;i<=n;i++){
        as[i]=0;
    }
    cout<<n;
    for(int i=1;i<=pow(2,n)-1;i++){
        add(n);
        if(sum()>=3 && ant()){
            aws++;
            if(aws>=998244353)aws-=998244353;
        }
    }
    cout<<aws;
}
