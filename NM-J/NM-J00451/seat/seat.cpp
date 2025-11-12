#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,num1,w;
bool mysort(int a,int b){
    return a>b;

}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    num1=a[1];
    sort(a+1,a+1+n*m,mysort);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            w++;
            if(a[w]==num1){
                if(i%2==0) cout<<i<<" "<<n+1-j<<endl;
                else cout<<i<<" "<<j<<endl;
            }
        }
    }
    return 0;
}
