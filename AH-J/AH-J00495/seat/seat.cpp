#include <bits/stdc++.h>
using namespace std;
int n,m;
int c,r;
int a[110];
int ans;
int xy;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<(n*m);i++){
        cin>>a[i];
    }
    ans=a[0];
    for (int i=0;i<(n*m);i++){
        for (int j=i+1;j<(n*m);j++){
            if (int(a[i])<int(a[j])){
                int changes=a[i];
                a[i]=a[j];
                a[j]=changes;
            }
        }
    }
    for (int i=0;i<(n*m);i++){
        if (a[i]==ans) xy=i+1;
    }
    c=xy/m;
    if (c%m!=0 && xy>m){
        c++;
        cout<<c<<" ";
    }
    else cout<<c<<" ";
    if (c%2==0){
        int b=xy%m;
        r=m+1-b;
    }
    else if(xy%m==0){
        if (c%2==0) r=1;
        else r=m;
    }
    else r=(xy%m);
    cout<<r;
    return 0;
}
