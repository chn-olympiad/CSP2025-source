#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,x,y,f;
int a[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    y=n*m;
    for(int i=1;i<=y;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+y+1,greater<int>());
    for(int i=1;i<=y;i++){
        if(a[i]==x){
            f=i;
            break;
        }
    }
    int fu=ceil(f*1.0/n);
    int k=f-(n*(fu-1));
    if(fu%2==1){
        cout<<fu<<" "<<k;
    }
    else cout<<fu<<" "<<n+1-k;
    return 0;
}

