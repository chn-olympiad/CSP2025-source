#include<bits/stdc++.h>
using namespace std;
int a[150];
int score[150];
struct Edge{
    int s;
    int line;
    int hin;
}g[150];
bool cmp(Edge a,Edge b){
    return a.s>b.s;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r,a1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>g[i].s;
    }
    a1=g[1].s;
    sort(g+1,g+1+n*m,cmp);
    int line,hin;
    for(int i=1;i<=n*m;i++){
       if(g[i].s==a1){
            if(i<=m){
                line=1;
                hin=i;
            }
            else{
                line=1+i/m;
                if(line%2==0){
                    hin=m-i%m+1;
                }
                else{
                    hin=i%m;
                }
            }
            cout<<line<<" "<<hin;
            break;
       }
    }
    return 0;
}
