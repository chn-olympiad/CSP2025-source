#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.in","r".stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    bool o=1;
    for(int i=1;i<=n*m;i++){
        if(a[i]!=i){
            o=0;
        }
    }
    if(o==1){
        cout<<n<<" "<<m;
        return 0;
    }else{
        bool l=1;

        for(int i=1;i<=n*m;i++){
            int r=n*m-i+1;
            if(a[i]!=r){
                l=0;
            }
        }
        if(l==1){
            cout<<1<<" "<<1;
            return 0;
        }
    }
    return 0;
}
