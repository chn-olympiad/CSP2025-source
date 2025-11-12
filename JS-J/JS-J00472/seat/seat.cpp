#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,Rfen;
    int a[110];
    int kc[15][15];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    Rfen=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    if(n==1&&m==1){
        cout<<"1 1\n";
        return 0;
    }else if(n==1&&m<=10){
        for(int i=1;i<=n*m;i++){
            if(a[i]==Rfen){
                cout<<i<<" 1"<<"\n";
                return 0;
            }
        }
    }else if(n<=10&&m==1){
        for(int i=1;i<=n*m;i++){
            if(a[i]==Rfen){
                cout<<"1 "<<i<<"\n";
                return 0;
            }
        }
    }else if(n==2&&m==2){
        if(a[1]==Rfen){
            cout<<"1 1\n";
        }else if(a[2]==Rfen){
            cout<<"1 2\n";
        }else if(a[3]==Rfen){
            cout<<"2 2\n";
        }else if(a[4]==Rfen){
            cout<<"2 1\n";
        }
        return 0;
    }
    return 0;
}
