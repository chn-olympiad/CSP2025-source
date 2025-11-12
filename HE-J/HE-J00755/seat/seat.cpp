#include<bits/stdc++.h>
using namespace std;
int n,m,r,res;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    for(int i=1;i<=n*m;i++){
        int no;
        cin>>no;
        if(no>r){
            res++;
        }
    }
    int c=1,r=1;
    bool up=1;
    while(res--){
        if(up){
            r++;
        }else{
            r--;
        }
        if(r>n){
            r=n,up=0,c++;
        }else if(r<1){
        	r=1,up=1,c++;
		}
    }
    cout<<c<<' '<<r;
    return 0;
}
