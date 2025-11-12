#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long sum=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        int sa=0,maxa=0;
        for(int j=0;j<i;j++){
            sa+=a[j];
            maxa=max(maxa,a[j]);
        }
        if(maxa*2<sa){
            sum++;
        }
    }
    cout<<sum%998244353;
    return 0;
}
