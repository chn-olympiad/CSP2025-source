#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=100+10;
int a[maxn];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int s=a[1];
    sort(a+1,a+n*m+1,cmp);
    int p=0;
    for(int i=1;i<=n*m;i++){
        if(a[i]==s){
            p=i;
            break;
        }
    }
    int o=0;
    if(p%n==0){
        o=p/n;
    }
    else o=p/n+1;
    if(o%2==0){
        cout<<o<<" "<<o*n-p+1;
    }
    else cout<<o<<" "<<p-(o-1)*n;
    return 0;
}
