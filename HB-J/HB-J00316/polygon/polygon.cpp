#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
long long sum;
long long c(int x,int y){
    int s=1;
    for(int i=1;i<=x;i++){
        s*=i;
    }
    int s1=1;
    for(int i=1;i<=y;i++){
        s1*=i;
    }
    int s2=1;
    for(int i=1;i<=x-y;i++){
        s2*=i;
    }
    return s/(s1*s2);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        sum+=c(n,i);
    }
    cout<<sum%998%244%353;
    return 0;
}
