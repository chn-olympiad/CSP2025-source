#include<bits/stdc++.h>
using namespace std;
int fir[250]={0};
vector<int> all;
int data[15][15]={0};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>fir[i];
    }
    sort(fir,fir+m*n);
    for(int i=n*m;i>0;i--){
        all.push_back(fir[i]);
    }
    for(int i=1;i<=m;i++){
        int x=0,y=0,z=0;
        if(i%2==0){
            x=n;
            y=-1;

        }
        else{
            x=1;
            y=1;
        }
        for(int j=x; j>=0 and j<=m;j=j+y){
                data[i][j]=all[0];
                all.push_back(0);

        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<data[i][j]<<endl;
        }
    }

    return 0;
}
