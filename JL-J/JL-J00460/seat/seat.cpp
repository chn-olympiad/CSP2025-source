#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int num=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[++num];
        }
    }
    int r=a[1];
    sort(a+1,a+1+num,cmp);
    int k=0;
    for(int i=1;i<=num;i++){
        if(a[i]==r){
            k=i;
        }
    }
    int x=0,y=0;
    if(k%n)x=k/n+1;
    else x=k/n;
    if(x%2){
        y=k%n;
        if(y==0)y=n;
    }
    else{
        y=n-(k%n)+1;
        if(y==n+1)y=1;
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
