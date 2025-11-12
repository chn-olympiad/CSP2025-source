#include<bits/stdc++.h>
using namespace std;
bool boooo(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,llll;
    cin>>m>>n;

    int c[n*m+1]={0};
    for(int i=1;i<=n*m;i++){
        cin>>c[i];
    }
    llll=c[1];
    sort(c+1,c+1+n*m,boooo);
    for(int i=1;i<=n*m;i++){
        if(c[i]==llll){
            cout<<int(double(i)/double(m)+0.9)<<" ";
            if(int(double(i)/double(m)+0.9)%2==0){
                cout<<n-(i%(n+1));
            }else{
                if(i%n==0) cout<<n;
                else cout<<i%n;
            }


            return 0;
        }

    }
    return 0;

}

