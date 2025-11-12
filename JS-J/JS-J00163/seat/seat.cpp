#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n,m,a[maxn],mark[10000],target;
bool cmp(int A,int B){
    return A > B;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n*m;i++){
        cin>>mark[i];
    }
    target = mark[1];
    sort(mark+1,mark+n*m+1,cmp);
    int id;
    for(int i = 1;i <= n*m;i++){
        if(mark[i]==target){
            id = i;
            break;
        }
    }
    int x,y;
    x = y = 1;
    while(1){
        if(id-n-n>0){
            id = id-n-n;
            x+=2;
        }
        else break;
    }
    if(id>n){
        id-=n;
        x++;
        cout<<x<<" "<<n-id+1;
    }
    else{
        cout<<x<<" "<<id;
    }
    return 0;
}
