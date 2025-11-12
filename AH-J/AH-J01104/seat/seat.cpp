#include<bits/stdc++.h>
using namespace std;
int a[1000001];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int r=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i]==r){
            if((i/m)%2==0){
                cout<<i/m+1<<" "<<1+i%m;
            }else{
                cout<<i/m+1<<" "<<n-i%m;
            }
        }
    }
    return 0;
}

