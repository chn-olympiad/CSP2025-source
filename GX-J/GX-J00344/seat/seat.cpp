#include<bits/stdc++.h>
using namespace std;
const int N=15;
int n,m;
int x,level;
int a[N*N];
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
    x=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(x==a[i]) level=i;
    }
    int i=1,j=1;
    int way=1; // 1 is down ,-1 is up
    while(--level){
        if(i+way>n||i+way<1){
            way=-way;
            j++;
        }
        else{
            i+=way;
        }
    }
    cout<<j<<" "<<i;
    return 0;
}
