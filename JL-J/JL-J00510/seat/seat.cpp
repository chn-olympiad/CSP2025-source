#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
int a[N],b[15][15];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int t=a[0],len=0;
    sort(a,a+(n*m),cmp);
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=m;j++){
                b[i][j]=a[len];
                len++;
                if(b[i][j]==t){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
        else{
            for(int j=m;j>=1;j--){
                b[i][j]=a[len];
                len++;
                if(b[i][j]==t){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
