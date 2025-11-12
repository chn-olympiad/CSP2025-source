#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
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
    int x=a[0];
    sort(a,a+n*m,cmp);
    int y;
    for(int i=0;i<n*m;i++){
        if(a[i]==x){
            y=i;
            break;
        }
    }
    int b=y/n;
    int c=y%n;
    if(b%2==0){
        cout<<b+1<<' '<<c+1;
    }else{
        cout<<b+1<<' '<<n-c;
    }
    return 0;
}
