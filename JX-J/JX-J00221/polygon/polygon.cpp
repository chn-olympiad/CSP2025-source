#include<bits/stdc++.h>
int a[5005];
int num,maxx=-1000,ans;
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        num+=a[i];
        maxx=max(maxx,a[i]);
    }
    int u;
    if(num%2==1){
        u=(num/2)+1;
    }else{
        u=num/2;
    }
    if(u>maxx){
        ans++;
    }
    cout<<ans;
    return 0;
}
