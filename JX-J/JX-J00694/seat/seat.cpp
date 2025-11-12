#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105],b[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,y;
    int sum,cnt;
    cin >> n >> m;
    cin >> sum;
    a[1]=sum;
    for(int i=1;i<=n*m-1;i++){
        cin >> a[i+1];
    }
        sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        b[i]=a[n*m+1-i];
    }
    for(int i=1;i<=n*m;i++){
        if(b[i]==sum){
            cnt=i;
        }
    }
  //  cout << cnt << endl;
    if(cnt%n!=0){
        y=cnt/n+1;
    }
    else{
        y=cnt/n;
    }
    if(y%2==0){
        x=y*n-cnt+1;
    }
    else{
        x=n-(y*n-cnt);
    }
    cout << y << ' ' << x;
    return 0;
}
