#include<bits/stdc++.h>
using namespace std;
int s[11][11],k[101];
bool cmp(int a,int b){
         return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,g,u;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>k[i];
    }
    int y=k[1];
    sort(k+1,k+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(k[i]==y){
            g=i;
        }
    }
    int x=g%n;
    int h=g%(n*2);
    if(g%n==0){
        x=n;
    }
    if(g%(n*2)==0){
        g=n;
    }
    if(g/n==0){
        u=g/n;
    }
    else{
        u=g/n+1;
    }
    if(h<=n){
        cout<<u<<" "<<x<<" ";
        return 0;
    }
    if(h>n){
        cout<<u<<" "<<h-x<<" ";
        return 0;
    }

}
