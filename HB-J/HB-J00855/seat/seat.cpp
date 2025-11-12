#include<bits/stdc++.h>
using namespace std;
int R;
int al[105];
int ma[12][12];
int x,y;
int f=1;
int step;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k=n*m;
    cin>>R;
    for(int i=0;i<k-1;i++){
        cin>>al[i];
    }
    al[k-1]=R;
    sort(al,al+k,cmp);
    int g;
    for(int i=0;i<k;i++){
        if(al[i]==R){
            g=i;
        }
    }
    g++;
    int pxo=g%n;
    if(pxo){
        int pyo=(g-pxo)/n+1;
        y=pyo;
        if(pyo%2==1){
            x=pxo;
        }
        else{
            x=n-pxo+1;
        }
    }
    else{
        int ans=g/n;
        y=ans;
        if(ans){
            x=n;
        }
        else{
            x=1;
        }
    }

    cout<<y<<" "<<x;
    return 0;
}
