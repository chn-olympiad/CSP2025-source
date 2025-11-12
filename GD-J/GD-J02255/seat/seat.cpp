#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
int n,m;
int a[105];
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        cin >> a[i];
    }
    int b=a[1];
    sort(a+1,a+n*m+1,cmp);
    int x = 0;
    for(int i = 1;i <= m*n;i++){
        if(a[i]==b){
            x = i;
            break;
        }
    }
    if(x%n==0){
        if((x/n)%2==0){
            cout << x/n << " " << 1;
        }
        else{
            cout << x/n << " " << n;
        }
    }
    else{
        int c = x/n+1;
        if(c%2==0){
            cout << c << " " << n-(x%n)+1;
        }
        else{
            cout << c << " " << x%n;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
