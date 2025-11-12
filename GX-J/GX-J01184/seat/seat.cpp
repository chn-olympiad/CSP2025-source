#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y,rchair=0;
    cin>>x>>y;
    int bbbbb[105]={};
    cin>>bbbbb[1];
    rchair=bbbbb[1];
    for(int i=2;i<=x*y;i++){
        cin>>bbbbb[i];
    }
    sort(bbbbb+1,bbbbb+1+(x*y));
    int mx=1,my=1,djg=x*y;
    while(my<=y){
        if(bbbbb[djg]==rchair){
            cout<<mx<<" "<<my;
            return 0;
        }
        if(my%2==0){
            mx++;
            if(mx>x){
                my++;
                mx--;
            }
        }else{
            mx--;
            if(mx<1){
                my++;
                mx++;
            }     
        }
        djg--;
    }
    return 0;
}
