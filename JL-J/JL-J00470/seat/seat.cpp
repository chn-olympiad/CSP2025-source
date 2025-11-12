#include<bits/stdc++.h>
using namespace std;
int a[10000];
bool cmp(int x,int y){
    return x > y;
} int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,R,c,r;
    cin >> n >> m;
    for(int i=0;i<n*m;i++){
        cin >> a[i];
    } R = a[0];
    sort(a,a+(n*m),cmp);
    for(int i=0;i<n*m;i++){
        if(a[i] == R){
            R = i;
            c = R / n + 1;
            r = R % n + 1;
            if(c % 2 == 0){
                cout << c << " " << (n+1-r);
            } else {
                cout << c << " " << r;
            }
        }
    } return 0;
}
