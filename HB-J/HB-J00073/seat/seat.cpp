#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
bool cmp(int w,int q){
    return w>q;
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
    for(int i=1;i<=n*m;i++){
        if(a[i]==s){
            s=i;
            break;
        }
    }

    int f1=s/n;
    int f2=s%n;

    if(f2==0){
        if(f1%2==0) {
            cout<<f1<<' '<<1;
        }
        else {
            cout<<f1<<' '<<n;
        }
    }
    else{
        if(f1%2==0) {
            cout<<f1+1<<' '<<f2;
        }
        else {
            cout<<f1+1<<' '<<n-f2+1;
        }
    }
    return 0;
}
