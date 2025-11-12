#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005]={},cnt1=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)cnt1++;
    }
    if(cnt1==n){
        cout<<n-2;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j+=i){
            int sum=0,maxx=0;
            for(int k=j;k<=j+i;k++){
                sum+=a[k];
                maxx=max(maxx,a[i]);
            }
            if(maxx*2<sum)cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
