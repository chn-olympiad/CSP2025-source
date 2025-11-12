#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int a,cnt;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a;
    for(int i=1,u;i<n*m;i++){
        cin>>u;
        if(u>a) cnt++;
    }
    cnt++;
    int l=cnt/n+1,h=cnt%n;
    if(h==0) h=n,l--;
    if(l%2){
        cout<<l<<" "<<h;
    } else {
        cout<<l<<" "<<n-h+1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
