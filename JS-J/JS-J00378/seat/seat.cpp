#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,seat[120],cnt=1,c,r;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>seat[i];
        if(seat[i]>seat[0]){
            cnt++;
        }
    }
    //cout<<cnt<<endl;
    c=cnt/m;
    if(cnt%m!=0){
        c=c+1;
    }
    if(cnt%m==0){
        r=n;
        cout<<c<<' '<<r;
        return 0;
    }
    if(c%2==0){
        r=n-(cnt%n)+1;
    }
    if(c%2!=0){
        r=cnt%n;
    }
    cout<<c<<' '<<r;
    return 0;
}
