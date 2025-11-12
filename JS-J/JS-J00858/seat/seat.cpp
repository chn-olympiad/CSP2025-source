#include<bits/stdc++.h>
using namespace std;
int n,m,a[10009],sum=1,c=1;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n*m;++i){
        cin>>a[i];
        if(a[i]>a[1])sum++;
    }
    while(sum>n){
        sum-=n;
        c++;
    }
    cout<<c<<" ";
    if(c%2==1)cout<<sum;
    else cout<<n-sum+1;
    return 0;
}
