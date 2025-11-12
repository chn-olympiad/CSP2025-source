#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int h,l,chengji,n,cnt=0;
    cin>>h>>l>>chengji;
    for(int i=1;i<=h*l-1;i++){
        cin>>n;
        if(n>chengji){
            cnt++;
        }
    }
    if((cnt/h+1)%2==0){
        cout<<cnt/h+1<<" "<<h-cnt%l;
    }
    if((cnt/h+1)%2==1){
        cout<<cnt/h+1<<" "<<cnt%l+1;
    }
    return 0;
}
