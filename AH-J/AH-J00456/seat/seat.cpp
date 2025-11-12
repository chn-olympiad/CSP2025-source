#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m,n;
    cin>>n>>m;
    int b=m*n;
    int c=0;
    vector<int>a(b+1,-100);
    for(int i=1;i<=b;i++){
            cin>>a[i];
    }
    int ans=a[1];
    sort(a.begin(),a.end());
    for(int i=b;i>0;i--){
        if(a[i]==ans){
            c=b-i+1;
            break;
        }
    }

    int y=1,x=1;

    if(c%n==0)x=c/n;
    else x=c/m+1;

    if(x%2==1&&x-1!=0){
        y=c%n;
    }
    else   if(x%2==1&&x==1){
        y=c;
    }
    else y=n-c%n+1;

    cout<<x<<" "<<y;
    return 0;
}
