#include<bits/stdc++.h>
using namespace std;
int n,a[5003];
long long ans=0;
void abc(int x,int y,long long p){
    for(int i=x;i<=n;i++){
        if(y>=3&&a[i]*2<p+a[i]){
            ans++;
        }
        if(i<n){
            abc(i+1,y+1,p+a[i]);
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    abc(1,1,0);
    cout<<ans%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
