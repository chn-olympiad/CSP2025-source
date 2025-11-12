#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],a1;
bool cmp(int x1,int x2){
    return x1>x2;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>a1;
    a[1]=a1;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    int cnt=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){ 
                if(a[cnt]==a1){
                    cout<<i<<" "<<j<<endl;
                }
                cnt++;
            }
        }else{
            for(int j=n;j>=1;j--){
                if(a[cnt]==a1){
                    cout<<i<<" "<<j<<endl;
                }
                cnt++;
            }
        }
    }
}