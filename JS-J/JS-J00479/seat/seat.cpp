#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],no,id=1;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1) no=a[i];
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]>no) id++;
    }
    int c=id/n,s=id%n;
    if(s==0){
        if(c%2==1) cout<<c<<' '<<n;
        else cout<<c<<" 1";
    }else{
        if((c+1)%2==1) cout<<c+1<<' '<<s;
        else cout<<c+1<<' '<<n-s+1;
    }
    return 0;
}
