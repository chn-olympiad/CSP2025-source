#include<bits/stdc++.h>
using namespace std;

int n=0,m=0;
int num[102]={0};
int fen=0;
int x=1,y=1,f=0;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1 ; i<=n*m ; i++){
        cin>>num[i];
    }
    fen=num[1];
    sort(num+1,num+n*m,cmp);
    for(int i=1 ; i<=n*m ; ){
        if(num[i]==fen){
            cout<<y<<" "<<x;
            return 0;
        }
        if(f==0 && x+1<=n){
            x++;
            i++;
            continue;
        }
        if(f==1 && x-1>=1){
            x--;
            i++;
            continue;
        }
        if(x+1>n || x-1<1){
            y++;
            i++;
            f=!f;
            continue;
        }
    }
    return 0;
}
