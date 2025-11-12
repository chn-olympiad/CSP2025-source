#include <bits/stdc++.h>
using namespace std;
int a[105],sum=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    cin >> a[1];
    for(int i=2;i<=n*m;i++){
        cin >> a[i];
        if(a[i]>a[1]){
            sum++;
        }
    }
    int h,l;
    if(sum%n==0){
        l=sum/n;
        if(l%2==1){
            h=n;
        }else{
            h=1;
        }
    }else{
        l=sum/n+1;
        if(l%2==1){
            h=sum%n;
        }else{
            h=(n+1)-(sum%n);
        }
    }
    cout << l << " " << h << endl;
    return 0;
}
