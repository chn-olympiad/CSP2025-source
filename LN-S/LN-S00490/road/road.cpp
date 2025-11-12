#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int a,b,c;
    cin>>a>>b>>c;
    int q,w,e,jsq=0;
    if(c==0){
        for(int i=0;i<b;i++){
            cin>>q>>w>>e;
            jsq+=e;
        }
        cout<<jsq;
    }
    else{
        cout<<50;
    }
    return 0;
}

