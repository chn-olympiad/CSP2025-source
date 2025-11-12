#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,m,w,p;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=(n*m);i++){
        cin>>a[i];
        if(i==1) w=a[i];
    }
    sort(a+1,a+(n*m)+1,cmp);
    for(int i=1;i<=(n*m);i++){
        if(a[i]==w){
            p=i;break;
        }
    }
    int c=((p-1)/n)+1;
    cout<<c<<" ";
    if(c%2==0){
        cout<<n-(p-(c-1)*n)+1;
    }
    else{
        cout<<(p-(c-1)*n);
    }
    return 0;
}
