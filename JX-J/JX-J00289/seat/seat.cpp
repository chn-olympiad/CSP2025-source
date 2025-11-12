#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n,m;
int a[N],b[N][N];
int w,ans = 0;
int cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        cin >> a[i];
    }
    w = a[1];
    sort(a+1,a+(n*m)+1,cmp);
    for(int i = 1;i <= n*m;i++){
        if(a[i] == w){
            w = i;
        }
    }
    for(int i = 1;i <= n;i++){
        if(w-i*n != 0){
            ans = i;
        }
    }
    cout << ans << " ";
    if(ans==2||ans==4||ans==6||ans==8||ans==10){
        cout << m-(w-n*(ans-1))+1;
    }else cout << w-n*(ans-1);
    return 0;
}
