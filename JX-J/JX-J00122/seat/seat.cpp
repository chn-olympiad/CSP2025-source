#include<bits/stdc++.h>
using namespace std;
long long n,m,cj[240],k,v;
bool pd(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>cj[i];
    }
    v=cj[1];
    sort(cj+1,cj+n*m,pd);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int l=1;l<=n;l++){
                k+=1;
                if(cj[k]==v){
                    cout<<i<<" "<<l;
                }
            }
        }else{
            for(int l=n;l>=1;l--){
                k+=1;
                if(cj[k]==v){
                    cout<<i<<" "<<l;
                }
            }
        }

    }
    return 0;
}
