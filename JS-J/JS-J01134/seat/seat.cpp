#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
struct seat{
    int x;
    int y;
}seats[105];
void seat_into(int a,int b){
    for(int i=1;i<=b;i++){
        if(i%2==1){
            for(int j=1;j<=a;j++){
                seats[(i-1)*a+j].x=j;
                seats[(i-1)*a+j].y=i;
            }
        }
        if(i%2==0){
            for(int j=1;j<=a;j++){
                seats[i*a-j+1].x=j;
                seats[i*a-j+1].y=i;
            }
        }
    }
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    seat_into(n,m);
    int a[105];
    cin>>a[1];
    int rssc=a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==rssc){
            cout<<seats[i].y<<" "<<seats[i].x;
        }
    }
    return 0;
}
