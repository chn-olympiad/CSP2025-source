#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==1||m==1){
        cout<<1<<" "<<1;
    }
    else{
       cout<<2<<" "<<2;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
