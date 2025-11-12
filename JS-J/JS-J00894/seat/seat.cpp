#include <bits/stdc++.h>
using namespace std;
int s[11][11];
int b[102];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int e;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    e=b[1];
    int f=0;
    int x,y;
    int q=1,w=1;
    sort(b+1,b+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(q==1&&w%2==1){
            x=1,y=0;
        }
        if(q==n&&w%2==1){
            x=0,y=1;
        }
        if(q==1&&w%2==0){
            x=0,y=1;
        }
        if(q==n&&w%2==0){
            x=-1,y=0;
        }
        s[q][w]==b[i];
        if(b[i]==e){
            cout<<w<<" "<<q;
            break;
        }
        q+=x;
        w+=y;

    }
    return 0;
}
