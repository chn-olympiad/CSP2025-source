#include<bits/stdc++.h>
using namespace std;
int n,m,a[400],id,x=1,y=1,sum=1;
bool cmp(int A,int B){
    return A>B;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    id=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int j=1;j<=m;j++){
            if(j%2==1){
                for(int i=1;i<=n;i++){
                    if(a[sum]==id){
                        cout<<j<<' '<<i;
                        return 0;
                    }
                    sum++;
                }
            }else{
                for(int i=n;i>=1;i--){
                    if(a[sum]==id){
                        cout<<j<<' '<<i;
                        return 0;
                    }
                    sum++;
                }
            }
    }
    return 0;
}
