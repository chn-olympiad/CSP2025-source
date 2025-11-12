#include<bits/stdc++.h>
using namespace std;
int a[1010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int R=a[1];
    int num=m*n;
    int pm=0;
    sort(a+1,a+1+num,cmp);
    for(int i=1;i<=num;i++){
        if(a[i]==R){
            pm=i;
            break;
        }
    }
    int l=(pm+n-1)/n,h=pm%n;
    if(h==0){
        h=n;
    }
    if(l%2==0){
        h=n-h+1;
    }
    cout<<l<<" "<<h;
    return 0;
}
