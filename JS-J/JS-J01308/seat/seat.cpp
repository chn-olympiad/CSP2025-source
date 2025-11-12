#include <bits/stdc++.h>
using namespace std;
const int N=5e2+10;
int a[N];
bool hz(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    //n is hang m is lie
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    int num=a[1];//the point of R
    sort(a+1,a+n*m+1,hz);
    int paim=0;
    for(int i=1;i<=m*n;i++){
        if(a[i]==num){
            paim=i;
            break;
        }
    }
    int l=paim/m+bool(paim%m),h;
    if(l%2){
        //ji shu lie
        if(paim%m){
            h=paim%m;
        }else{
            h=m;
        }
    }else{
        //ou shu lie
        h=m+1;
        h=h-paim%m;
        h%=m;
    }
    cout<<l<<" "<<h;

    return 0;
}
