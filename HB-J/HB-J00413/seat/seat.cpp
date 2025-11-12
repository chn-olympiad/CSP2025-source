#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],cnt=1,c,r;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int g=a[1];
    sort(a+1,a+1+(n*m),cmp);
    for(int i=1;i<=(n*m);i++){
        if(g==a[i]){
           c=i/m;
           r=i%n;
                if(r==0){ r=i; }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
