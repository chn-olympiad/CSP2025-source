#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[105];
int main(){
    freopen("seat.in",'r',stdin);
    freopen("seat.out",'w',stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int h=1;
    for(int i=1;i<105;i++){
        if(a[1]<a[i])h+=1;
    }
    int r;
    int c;
    c=h/n+1;
    if(c%2==1){
        r=h%n+1;
    }
    else r=n-h%n+1;
    cout<<c<<" "<<r;
}
