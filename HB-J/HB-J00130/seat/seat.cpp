#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[100010];
int fun(int a,int b){
    if(a%b==0){
        return a/b;
    }else{
        return a/b+1;
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int s=a[0];
    sort(a,a+n*m);
    int q=lower_bound(a,a+m*n,s)-a;
    q=n*m-q;
    int l=fun(q,n);
    int h=0;
    if(l%2==0){
        h=n-q/n+1;
    }else{
        h=q%n;
        if(h==0) h=n;
    }
    cout<<l<<" "<<h;



    return 0;
}
