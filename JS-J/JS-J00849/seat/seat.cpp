#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
int xa,num;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    xa=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==xa){
            num=i;
            break;
        }
    }
    int l=num/n;
    if(num%n!=0){
        l++;
    }
    cout<<l<<" ";

    int h;
    int yu=num%n;
    if(yu==0){
        yu=n;
    }
    if(l%2==1){
        h=yu;
    }
    else{
        h=n+1-(yu);
    }
    cout<<h;
    return 0;
}
