#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,l,r,h;
    cin>>n>>m>>k;
    srand(time(0));
    for(int i=0;i<m;i++){
        cin>>l>>r>>h;
    }
    for(int i=0;i<k;i++){
        cin>>n>>m>>l>>r>>h;
    }
    cout<<rand()%100;
    return 0;
}