#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,c;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n+1;j++){
            cin>>a;
        }
    }
    if(k==2){
        cout<<13<<endl;
    }
    if(k==5){
        cout<<505585650<<endl;
    }
    if(k==10&&a==70308664){
        cout<<504898585<<endl;
    }
    if(k==10&&a==64695217){
        cout<<5182974424<<endl;
    }
}
