#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,mark,marki,ansx,ansy,zs;
    cin>>n>>m;
    zs=n*m;
    for(int i=1;i<=zs;i++){
        cin>>a[i];
    }
    mark=a[1];
    sort(a+1,a+zs+1);
    for(int i=1;i<=zs;i++){
        if(a[i]==mark){
            marki=zs-i+1;
            break;
        }
    }
    ansx=marki/n+1;
    if(marki%n==0) ansx-=1;
    if(ansx%2==1){
        ansy=marki%n;
        if(ansy==0) ansy=n;
    }
    else{
        ansy=marki%n;
        if(ansy==0) ansy=n;
        ansy=n+1-ansy;
    }
    cout<<ansx<<" "<<ansy;
    return 0;
}
