#include <bits/stdc++.h>
using namespace std;
int s=1;
int h,l;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,d;
    cin>>n>>m>>d;
    if(n==1&&m==1){
        cout<<1<<" "<<1;
        return 0;
    }
    for(int i=1;i<n*m;i++){
        int x;
        cin>>x;
        if(x>d)
            s++;
    }
    l=s/n+1;
    int y=s%n;
    if(y==0){
        l--;
        y++;
    }
    if(l%2){
        h=y;
    }
    else{
        h=n-y+1;
    }
    cout<<l<<" "<<h;
return 0;
}
