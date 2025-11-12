#include<bits/stdc++.h>
using namespace std;
long long a[100000],n,m,cnt=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n*m;i++){
        if(a[i]>a[1]){
            cnt++;
        }
    }
    cnt++;
    int x=cnt/n,y=cnt%n;
    if(y==0){
        cout<<x<<" "<<n;
    }else{
        cout<<x+1<<" ";
        if((x+1)%2==1){
            cout<<y;
        }else{
            cout<<n-y+1;
        }
    }


}
