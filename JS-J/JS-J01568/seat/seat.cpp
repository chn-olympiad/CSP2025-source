#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int sum=a[1];
    int xb=0;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==sum) xb=i;
    }
    if(xb%n==0){
        int s=xb/n;
        cout<<s<<" ";
        if(s%2==1){
            cout<<n;
        }
        else{
            cout<<1;
        }
    }
    else{
        int s=xb/n+1;
        cout<<s<<" ";
        if(s%2==1){
            cout<<xb%n;
        }
        else{
            cout<<n-xb%n+1;
        }
    }
    return 0;
}
