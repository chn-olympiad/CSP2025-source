#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,x,w;
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>x;
    a[1]=x;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==x){
            w=i;
            break;
        }
    }
    int l;
    if(w%n==0){
        l=w/n;
        if(l%2==0){
            cout<<l<<" "<<1;
        }else{
            cout<<l<<" "<<n;
        }
        return 0;
    }else{
        l=w/n+1;
    }
    cout<<l<<" ";
    if(l%2==0){
        cout<<(n-(w%n)+1);
    }else{
        cout<<w%n;
    }
    return 0;
}
