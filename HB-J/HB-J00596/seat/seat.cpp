#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n>>m;
    int XS=n*m;
    int w[XS];
    for(int i=0;i<XS;i++){
        cin >> w[i];
    }
    int RM = w[0];
    sort(w,w+XS);
    int nx=0,nl=1;
    bool fe = true;
    for(int i=XS-1;i>=0;i--){
        if(fe){
            nx+=1;
            if(nx>n){
                nx-=1;
                nl++;
                fe = false;
            }
            if(w[i]==RM){
                cout <<nl<<' '<<nx;
                return 0;
            }
        }else{
            nx-=1;
            if(nx<1){
                nx+=1;
                nl++;
                fe = true;
            }
            if(w[i]==RM){
                cout <<nl<<' '<<nx;
                return 0;
            }
        }
    }
    return 0;
}
