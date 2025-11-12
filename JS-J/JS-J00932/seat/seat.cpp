#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,y;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int num=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==num){
            num=i;
            break;
        }
    }
    if(num%n==0){
        x=num/n;
    }else{
        x=num/n+1;
    }
    num=num%n;
    if(x%2==1){
        y=num;
    }else{
        y=n+1-num;
    }
    if(y==0)y=n;
    cout<<x<<" "<<y<<endl;
    return 0;
}
