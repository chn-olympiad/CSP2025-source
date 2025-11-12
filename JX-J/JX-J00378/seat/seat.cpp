#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010],r;
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    r=a[1];
    int t=0;
    sort(a+1,a+1+n*m,cmp);
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n&&++t;i++){
                if(a[t]==r){
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
        }
        else{
            for(int i=n;i>=1&&++t;i--){
                if(a[t]==r){
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
        }
    }
    return 0;
}
/*

16 11  6
15 10  5
14  9  4
13  8  3
12  7  2

*/