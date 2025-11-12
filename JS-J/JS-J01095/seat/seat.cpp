#include <bits/stdc++.h>
using namespace std;

int n,m,R,point[105];

bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        cin >> point[i];
    }
    R = point[1];
    sort(point+1,point+n*m+1,cmp);
    int l = 1,r = n*m,mid = (l + r)/2;
    while(l <= r){
        if(point[mid] == R){
            break;
        }else if(point[mid] > R){
            l = mid + 1;
            mid = (l + r) / 2;
        }else{
            r = mid - 1;
            mid = (l + r) / 2;
        }
    }
    cout << mid << endl;
    if((mid / n) * n == mid){
        if((mid / n) % 2 == 0){
            cout << mid / n << " " << 1;
        }else{
            cout << mid / n << " " << n;
        }
    }else{
        if((mid / n) % 2 == 0){
            cout << mid / n + 1 << " " << mid % n;
        }else{
            cout << mid / n + 1 << " " << n - mid % n + 1;
        }
    }
    return 0;
}
