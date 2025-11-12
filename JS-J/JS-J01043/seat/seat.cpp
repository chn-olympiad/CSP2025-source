#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int c=a[0],pos=0;
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i]==c){
            pos=i;
            break;
        }
    }
    int l=pos/n+1;
    int r;
    if(l%2!=0){
        r=pos%n+1;
    }
    else{
        r=n-(pos%n+1)+1;
    }
    cout<<l<<" "<<r;
    return 0;
}
