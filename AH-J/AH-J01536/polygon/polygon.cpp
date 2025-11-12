#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll sum=0;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    if(sum<a[n-1]*2){
        cout<<0<<endl;
        return 0;
    }
    if(n<=3){
        sum=0;
        if(a[0]+a[1]>=max(a[0],a[1])*2) sum++;
        if(a[0]+a[2]>=max(a[0],a[2])*2) sum++;
        if(a[1]+a[2]>=max(a[1],a[2])*2) sum++;
        if(a[1]+a[2]+a[0]>=max(max(a[0],a[1]),a[2])*2) sum++;
        cout<<sum;
    }
    cout<<n*(n-1)+1<<endl;
    return 0;
}
