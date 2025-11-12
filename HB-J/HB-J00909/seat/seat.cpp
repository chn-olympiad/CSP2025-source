#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[1005];
    for(int i = 1;i <= n*m;i++){
        cin >> a[i];
    }
    int x = a[1],c,r;
    sort(a+1,a+n*m+1,cmp);
    for(int i = 1;i <= n*m;i++){
        if(a[i] == x){
            c = ceil(double(i)/double(n));
            if(c % 2 == 1){
                r = i%n;
                if(r == 0){
                    r = n;
                }
            }else{
                r = n - (i%n) + 1;
                if(r > n){
                    r = n;
                }
            }
            break;
        }
    }
    cout << c << " " << r << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}