#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,a[1005],id;
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
    int k=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==k){
            id=i;
        }
    }
    //cout<<id<<"\n";
    int y=id%n;
    int x;
    if(id%n==0){
        x=id/n;
    }
    else{
        x=id/n+1;
    }
    if(y==0){
        y=n;
    }
    if(x%2==1){
        cout<<x<<" "<<y;
    }
    else{
        cout<<x<<" "<<n-y+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

