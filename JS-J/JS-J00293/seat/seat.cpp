#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n*m; i++){
        cin>>a[i];
    }
    int ans=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1; i<=n*m; i++){
        if(a[i]==ans){
            int l,r;
            if(i%n==0)l=i/n;
            else l=i/n+1;
            if(l&1){
                r=i%n;
                if(r==0)r=n;
            }else{
                r=n-i%n+1;
                if(r==n+1)r=1;
            }
            cout<<l<<' '<<r<<endl;
        }
    }
    return 0;
}
