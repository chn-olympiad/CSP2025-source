#include<bits/stdc++.h>
using namespace std;
int n,m,a,cnt=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a;
    for(int i=2;i<=n*m;i++){
        int x;
        cin>>x;
        if(x>a){
            cnt++;
        }
    }
    int c=cnt/n,r=cnt%n;
    if(r==0){
        r=n;
    }else{
        c++;
    }
    if(c%2==0){
        r=n+1-r;
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
