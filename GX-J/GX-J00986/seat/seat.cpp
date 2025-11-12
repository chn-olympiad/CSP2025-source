#include<bits/stdc++.h>
using namespace std;
bool cmp(int c,int d){
    return c>d;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    int a[200],xm,o;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    xm=a[0];
    sort(a,a+n*m,cmp);
    int x,y;
    x=1;
    y=1;
    o=0;
    while(a[o]!=xm){
        if(x%2!=0){
            if(y==m){
                x++;
            }else{
                y++;
            }
        }else{
            if(y==1){
                x++;
            }else{
                y--;
            }
        }
        o++;
    }
    cout<<x<<" "<<y;
    return 0;
}
