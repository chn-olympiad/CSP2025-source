#include<bits/stdc++.h>
using namespace std;
int m,n;
struct node{
    int fen;
    int bh;
    int pm;
}a[110];
bool cmp(node a,node b){
    return a.fen>b.fen;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<m*n;i++){
        cin>>a[i].fen;
        a[i].bh=i+1;
    }
    int sr;
    sort(a,a+n*m,cmp);
    for(int i=0;i<m*n;i++){
        a[i].pm=i+1;
        if(a[i].bh==1){
            sr=a[i].pm;
            break;
        }
    }
    int lie=sr/n,hang,yu=sr%n;
    if(yu!=0){
        lie++;
    }
    if(lie%2==0){
        hang=n-yu+1;
    }else{
        hang=yu;
    }
    if(yu==0){
        hang=n;
    }
    cout<<lie<<" "<<hang;
    return 0;
}
