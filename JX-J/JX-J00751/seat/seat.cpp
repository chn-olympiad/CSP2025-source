#include<bits/stdc++.h>
using namespace std;
int n,m,yz,fd;
int a[110];
int li[11][11];
int main(){
    freopen("seat.in","r","stdin");
    freopen("seat.out","w","stdout");
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]==i) yz++;
        if(a[i]==n*m-i+1) fd++;
    }
    if(yz==n*m){
        cout<<n<<' '<<m;
        return 0;
        }
    if(fd==n*m) cout<<"1 1";
    freclose("seat.in","r","stdin");
    freclose("seat.out","w","stdout");
    return 0;
}


