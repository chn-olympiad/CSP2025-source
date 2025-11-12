#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int s = n*m + 1;
    int ma[s];
    for(int i=1;i<=n*m;i++){
        cin >> ma[i];
    }
    int rm = ma[1];
    sort(ma+1,ma+s,cmp);
    int cnt;
    for(int i=1;i<=n*m;i++){
        if(ma[i] == rm){
            cnt = i;
            break;
        }
    }
    if(cnt <= n){
        cout << 1 << " " << cnt;
    }
    else{
        int q = cnt/n;
        int p = cnt%n;
        if(q % 2 !=0){
            q++;
            if(p !=0 ){
                p = n - p + 1;
            }else{
                cout << q - 1 << " " << n;
                return 0;
            }
        }else{
            q++;
            if(p == 0){
                cout << q - 1 << " " << n;
                return 0;
            }
        }
        cout << q <<" "<< p;
    }
    return 0;
}
