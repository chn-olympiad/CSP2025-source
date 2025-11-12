#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m;
int a[110];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int r=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==r){
            r=i;
            break;
        }
    }
    int h,l;
    l=(r-1)/n+1;
    if(l%2==0){
        h=n-(r-(r-1)/n*n)+1;
    }else{
        h=r-(r-1)/n*n;
    }
    cout<<l<<" "<<h;
    return 0;
}

