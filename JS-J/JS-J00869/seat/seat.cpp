#include <bits/stdc++.h>
using namespace std;
int a[1010],ct,n,m;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin >> n >> m;
for(int i=1;i<=n*m;i++){
    cin >> a[i];
}
ct=a[1];
sort(a+1,a+n*m+1);
for(int j=m;j>=1;j--){
    if(j%2==1){
        for(int i=n;i>=1;i--){
            if(a[(m-j)*n+n-i+1]==ct) {
                cout << j << " " << i;
                break;
            }
        }
    }else {
    for(int i=1;i<=n;i++){
        if(a[(m-j)*n+i]==ct){
            cout << j << " " << i;
            break;
        }
    }
}
}
return 0;
}
