#include<bits/stdc++.h>
using namespace std;
int a[110],n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int x=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(i&1){
            for(int j=1;j<=m;j++){
                cnt++;
                if(a[cnt]==x){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }else{
            for(int j=m;j>=1;j--){
                cnt++;
                if(a[cnt]==x){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}