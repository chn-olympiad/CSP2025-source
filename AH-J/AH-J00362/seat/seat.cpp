#include<bits/stdc++.h>
using namespace std;
int sit[11][11];
int a[101];
int n,m;
int R;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];
    int cnt=1;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2){
            for(int j=1;j<=n;j++){
                sit[j][i]=a[cnt];
                if(a[cnt]==R){
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                sit[j][i]=a[cnt];
                if(a[cnt]==R){
                    cout<<i<<" "<<j;
                    return 0;
                }
                cnt++;
            }
        }
    }
    return 0;
}
