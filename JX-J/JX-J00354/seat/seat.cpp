#include<bits/stdc++.h>
using namespace std;

int n,m,n1,m1;
int a[101];
int cnt(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int c=n*m;
    for(int i=1;i<=c;i++){
        cin>>a[i];
    }
    int r = a[1];
    sort(a+1,a+c+1,cnt);
    for(int i=1;i<=c;i++){
        if(a[i]==r){
            r = i;
        }
    }
    if(r%n!=0){
        n1=r/n+1;
        if(n1%2==1){
            m1=r%n;
        }
        else{
            m1=n-r%n+1;
        }
    }
    else{
        n1=r/n;
        if(n1%2==1){
            m1=n;
        }
        else{
            m1=1;
        }
    }
    cout<<n1<<" "<<m1;
    return 0;
}
