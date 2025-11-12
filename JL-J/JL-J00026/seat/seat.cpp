#include<bits/stdc++.h>
using namespace std;
int s[105],n,m;
bool f(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>s[0];
    int k=s[0];
    for(int i=1;i<n*m;i++){
        cin>>s[i];
    }
    sort(s+0,s+n*m,f);
    int r=1;
    int i=0,x=1,y=1;
    while(s[i]!=k){
        if(r>0){
            if(y==n){
                x++;
                r=1-r;
            }else y++;
        }
        else{
            if(y==1){
                x++;
                r=1-r;
            }else y--;
        }
        i++;
    }
    cout<<x<<" "<<y;
    return 0;
}
