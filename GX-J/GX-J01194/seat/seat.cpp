#include <bits/stdc++.h>;
using namespace std;
bool b(int x,int y){
    if(x>y){
        return true;
    }else{
        return false;
    }

};
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,p=0,q=0,w;
    cin>>n>>m;
    int a[m][n],c[n*m],y=0;
    for(int i=0;i<n*m;i++){
        cin>>c[i];
        w=c[0];
    }
    if(n==1&&m==1){
        cout<<c[0];
        return 0;
    }
    sort(c,c+n*m,b);
    for(int i=0;i<n*m;i++){
        if(p%2==0){
            for(int j=q;j<n;j++){
                a[p][i]=c[y];
                y++;
                if(a[p][i]==w){
                    cout<<p<<" "<<i;
                    return 0;
                }
            }
            q=n-1;
        }else{
            for(int j=q;j>=0;j--){
                a[p][i]=c[y];
                y++;
                if(a[p][i]==w){
                    cout<<p<<" "<<i;
                    return 0;
                }
            }
            q=0;
        }
    }
    return 0;
}
