#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,a[101],l,s,cnt=0,x,y;
    cin>>m>>n>>l;
    a[l]=1;
    for(int i=1;i<m*n;i++){
        s=0;
        cin>>s;
        a[s]=1;
    }
    for(int z=l;z<=100;z++){
        if(a[z]==1)cnt++;
    }
    if(cnt%n==0){
        if((cnt/n)%2==0){
            x=cnt/n;
            y=1;
        }
        else{
            x=cnt/n;
            y=n;
        }
    }
    else{
        if(((cnt/n)+1)%2!=0){
            x=cnt/n+1;
            y=cnt%n+1;
        }
        else{
            x=cnt/n+1;
            y=n-(cnt%n)+1;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
