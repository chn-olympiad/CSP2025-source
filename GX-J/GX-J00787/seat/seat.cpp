
#include<bits/stdc++.h>
using namespace std;
const int MAXX=10010;
int a[110][110],chengji[MAXX],pai[MAXX];
int n,m,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>chengji[i];
        pai[i]=i;
    }
    for(int i=1;i<=n*m-1;i++){
        for(int j=i+1;j<=n*m;j++){
            if(chengji[i]<chengji[j]){
                swap(chengji[i],chengji[j]);
                swap(pai[i],pai[j]);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(pai[i]==1){
            x=i/n;
            int y1;
            if(i%n==0){
                y1=n;
            }
            else{
                y1=i%n;
            }
            if(x%2!=0){
                y=y1;
            }
            else{
                y=n+1-y1;
            }
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
