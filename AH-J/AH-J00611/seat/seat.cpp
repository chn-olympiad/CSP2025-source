/*
*/
#include<bits/stdc++.h>
#define N 15
using namespace std;
int n,m;
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
    int t=a[1];
    sort(a+1,a+n*m+1,cmp);
    int l=1,r=1;
    int cnt=1;
    while(true){
        if(a[cnt]==t){
            cout<<r<<" "<<l;
            break;
        }
        if(r&1){
            l++;
            if(l>n) l=n,r++;
        }else{
            l--;
            if(l==0) l=1,r++;
        }
        cnt++;
    }
    return 0;
}
