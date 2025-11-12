#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[210];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }int d=a[1],s;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==d){
            s=i;
            break;
        }
    }
    int x,y;
    if(s%n!=0)y=s/n+1;
    else y=s/n;
    if(s%n==0){
        if((s/n)%2==1)x=n;
        else x=1;
    }else{
        if((s/n)%2==0)x=s%n;
        else x=n-s%n+1;
    }
    cout<<y<<" "<<x;
    return 0;
}
