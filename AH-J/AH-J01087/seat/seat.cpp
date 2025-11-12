#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[105];
    int ans[105];
    for(int i=1;i<=n*m;i++){
        cin >> a[i];
    }
     for(int j=1; j<=n*m; j++){
        int max = 0;
        for(int q=1; q<=n*m; q++){
            if(a[q] >= max){
                max = a[q];
            }
        }
        ans[j] = max;
        for(int q=1; q<=n*m; q++){
            if(a[q] == max){
                a[q] = 0;
            }
        }
    }
    int h = 0;
    for(int i = 1;i<=n*m;i++){
        if(ans[i] == a[1]){
            h = i;
        }
    }
    int c = ((h-1)/n)+1;
    int r;
    int k = h%n;
    if(k == 0){
        k = n;
    }
    if(c%2 == 1){
        r = k;
    }else{
        r = n-k;
    }
    cout << c << ' ' << r << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
