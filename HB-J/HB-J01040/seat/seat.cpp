#include <iostream>
#include <algorithm>
using namespace std;

int cmp(int x,int y){
    return x>y;
}

int m,n,a[105],s,c,r,j;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> m >> n;
    for(int i=1;i<=m*n;i++){
        cin >> a[i];
    }
    s=a[1];
    sort(a+1,a+m*n+1,cmp);

    for(int i=1;i<=m*n;i++){
        if(a[i]==s) j=i;
    }

    if(j%n!=0) c=j/n+1;
    else c=j/n;

    if(j>n){
        if(c%2==0){
            if(j%n!=0) r=n-j%n+1;
            else r=1;
        }
        else r=j%n;
    }
    else r=j;
    cout << c << " " << r;
    return 0;
}
