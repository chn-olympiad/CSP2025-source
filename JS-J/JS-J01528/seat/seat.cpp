#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int a,int b){return a>b;}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    int rep=n*m;
    for(int i=1;i<=rep;i++){
        cin>>a[i];
    }
    //a[1]->R score
    int Rscore=a[1];
  //  cout<<Rscore<<" ";
    sort(a+1,a+rep+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2){
            for(int j=1;j<=n;j++){
                if(a[(i-1)*n+j]==Rscore){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }else{
            for(int j=n;j>=1;j--){
                if(a[(i-1)*n+(n-j+1)]==Rscore){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
