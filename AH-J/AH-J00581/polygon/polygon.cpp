#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[10000],cnt=0;
void solve(int t){

    int k=0;
    for(int i=t;i<n;i++){
        k+=a[i];
    }
    if(k>a[t-1] && n-t>=3){
        cnt++;
        for(int i=n-1;i>=t;i--){
            if(k>a[t-1]+a[i] && n-t>=3){
                cnt++;
            }
            else{
                break;
            }
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >>a[i];
    }
    sort(a+0,a+n+1);
    //if(n=3 &&a[1]<a[2]+a[3]){
    //    cout << 1;
    //    return 0;
    //}
    for(int i=0;i<n;i++){
        solve(i);
    }
    cout << cnt;
    return 0;
}
