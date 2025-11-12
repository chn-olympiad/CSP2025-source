#include<bits/stdc++.h>
using namespace std;
int n,m,qwe;
int pi,el[10005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>pi;
    el[0]=pi;
    for(int i=1;i<n*m;i++){
        cin>>el[i];
    }
    sort(el,el+n*m,cmp);
    qwe=0;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            for(int j=m;j>=1;j--){
                if(el[qwe]==pi){
                    cout<<i<<' '<<j;
                    return 0;
                }
                qwe++;
            }
        }else{
            for(int j=1;j<=m;j++){
                if(el[qwe]==pi){
                    cout<<i<<' '<<j;
                    return 0;
                }
                qwe++;
            }
        }
    }
    return 0;
}
