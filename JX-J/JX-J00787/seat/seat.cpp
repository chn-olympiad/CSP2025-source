#include<bits/stdc++.h>
using namespace std;
int num,f;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t,c,r;
    cin>>n>>m;
    t=n*m;
    int a[11][11],b[1000];
    for(int i=1;i<=t;i++){
        cin>>b[i];
    }
    f=b[1];
    sort(b+1,b+t+1);
    num=1;
    for(int c=1;c<=m;c++){
        if(m%2==0){
            for(int r=n;r>=1;r--){
                a[c][r]=b[num];
                num++;
            }
        }
        else{
            for(int r=1;r<=n;r++){
                a[c][r]=b[num];
                num++;
            }
        }
    }
    for(int c=1;c<=m;c++){
        for(int r=1;r<=n;r++){
            if(f=a[c][r]){
                cout<<c<<r;
                break;
            }
        }
    }
    return 0;
}
