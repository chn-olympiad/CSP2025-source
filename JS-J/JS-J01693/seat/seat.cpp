#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int d=a[1],f;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==d){
            f=i;
            break;
        }
    }
    int b,c;
    if(f%n!=0){
        b=f/n+1;
    }else{
        b=f/n;
    }
    if(b%2==1){
        if(f%n!=0){
            c=f%n;
        }else{
            c=n;
        }
    }else{
        if(f%n!=0){
            c=n-f%n+1;
        }else{
            c=1;
        }
    }
    cout<<b<<' '<<c;
    return 0;
}
