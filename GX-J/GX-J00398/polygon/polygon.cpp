#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[100];
int main(){
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> m;
    for(int i = 0 ; i < m ; i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < m-3; i++){
        if(a[i]+a[i+1]>a[i+2]) n++;
        if(a[i]+a[i+2]>a[i+3]) n++;
        if(a[i]+a[i+3]>a[i+4]) n++;
        if(a[i]+a[i+1]+a[i+2]>a[i+3]) n++;
        if(a[i]+a[i+1]+a[i+2]+a[i+3]>a[i+4]) n++;
    }
    if(a[m-2]+a[m-1]>a[m]) n++;
    cout << n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
