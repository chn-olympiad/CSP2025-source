#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int dj=1;
    int sc=0;
    cin>>sc;
    a[1]=sc;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>sc)dj++;
    }
    int h,l;
    int du=dj/(n*2)+1;
    if(dj%(n*2)==0)du--;
    int uz=dj%(n*2);
    if(uz==0)uz=n*2;


    l=(du-1)*2+1;
    if(uz>n)l++;


    if(uz<=n){
        h=uz;
    }
    if(uz>n){
        h=n*2-uz+1;
    }
    cout<<l<<" "<<h;
    return 0;
}
