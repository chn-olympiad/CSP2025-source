#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r,x,y;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    r=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i]==r){
            r=i;
            break;
        }
    }
    y=r%n;
    x=(r-y)/n;
    if(y==0){
        if(x%2==0){
            cout<<x+1<<" "<<1;
        }
        else{
            cout<<x+1<<" "<<n;
        }
    }
    else if(x%2==0){
        cout<<x+1<<" "<<n-(y-1);
    }
    else{
        cout<<x+1<<" "<<y+1;
    }
    return 0;
}
