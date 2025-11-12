#include<bits/stdc++.h>
using namespace std;
int n,m,fuckhim;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>fuckhim;
    int huh=0;
    for(int i=2;i<=(n*m);i++){
        int wawa;
        cin>>wawa;
        if(wawa>fuckhim)huh++;
    }
    cout<<huh%n+1<<" "<<huh/n+1;
    return 0;
}
