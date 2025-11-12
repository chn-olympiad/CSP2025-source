#include<bits/stdc++.h>
using namespace std;
int a[101],n,m;
bool cmp(int A,int B){
    return A>B;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int d=a[1],cnt=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                cnt++;
                if(a[cnt]==d){
                    cout<<i<<' '<<j;
                    break;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                cnt++;
                if(a[cnt]==d){
                    cout<<i<<' '<<j;
                    break;
                }
            }
        }
    }
    return 0;
}
