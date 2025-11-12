#include<bits/stdc++.h>
using namespace std;
int a[105];
int seat[15][15];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int a[5005];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(int i=3;i<=n;i++){
        if(a[i-2]+a[i-1]+a[i]>max(max(a[i-1],a[i-2]),a[i])) sum++;
    }
    cout<<sum;
    return 0;
}
