#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int x=a[1],t;
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            t=i;
            break;
        }
    }
    int tmp=(t+n-1)/n;
    cout<<tmp<<" ";
    if(tmp%2==1)cout<<(t-1)%n+1;
    else cout<<n-(t-1)%n;
    return 0;
}
