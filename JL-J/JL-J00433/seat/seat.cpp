#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,cnt=1;
    cin >>n>>m;
    int N;
    cin >>N;
    for(int i =2;i<=m*n;i++){
        cin >>a;
        if(a>N)cnt++;
    }
    int x,y;
    x=cnt/n;
    if(cnt%n>0)x++;
    if(cnt<n+1){
        y=cnt;
        cout <<x<<" "<<y;
        return 0;
            }
    if(x%2==0){
        y=n-(cnt%(n+1));
        cout <<x<<" "<<y;
        return 0;
    }
    y=cnt%n;
    if(y==0)y=1;
    cout <<x<<" "<<y;



return 0;
}
