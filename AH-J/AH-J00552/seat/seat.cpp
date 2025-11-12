#include<bits/stdc++.h>
using namespace std;
int n,m,a[200],l,cnt=0,ans[20][20],x;
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    l=n*m;
    for(int i=1;i<=l;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+l+1,cmp);
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                cnt++;
                ans[i][j]=a[cnt];
            }
        }
        else if(j%2==0){
            for(int i=n;i>=1;i--){
                cnt++;
                ans[i][j]=a[cnt];
            }
        }
    }
    bool ok=false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ans[i][j]==x){
                ok=true;
                cout<<j<<" "<<i;
                break;
            }
        }
        if(ok==true) break;
    }
    return 0;
}
