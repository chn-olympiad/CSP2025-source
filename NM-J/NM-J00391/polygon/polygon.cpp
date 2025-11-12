#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long sum=0;
bool check(int x,int y){
    long long zc=0;
    int maxa=0;
    for(int i=x;i<=y;i++){
        zc+=a[i];
        maxa=max(maxa,a[i]);
    }
    return y-x>=3&&zc>maxa*2;
}
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(check(i,j)==1){
                sum++;
            }
        }
    }
    cout<<sum%998244353;
    return 0;
}
