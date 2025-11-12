#include <bits/stdc++.h>
using namespace std;
int n,m,x,num,ans,c=1,r=1,s=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>num;
    for(int i=1;i<n*m;i++){
        cin>>x;
        if(x>num){
            ans++;
        }
    }
    while(ans>0){
        ans--;
        if(r+s>n){
            s=-1;
            c++;
            continue;
        }
        if(r+s<1){
            s=1;
            c++;
            continue;
        }
        r+=s;
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
