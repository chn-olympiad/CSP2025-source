#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[110];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    int s=a[1];
    sort(a+1,a+n*m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                cnt++;
                if(a[cnt]==s){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }else if(i%2==0){
            for(int j=n;j>=1;j--){
                cnt++;
                if(a[cnt]==s){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
