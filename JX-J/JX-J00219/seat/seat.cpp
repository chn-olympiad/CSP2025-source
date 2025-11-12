#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int x = 1,y = 1,d = 0;
    cin>>n>>m;
    int a[1001];
    int lenn = n * m;
    for(int i = 0;i < lenn;i++){
        cin>>a[i];
    }
    int a1 = a[0];
    sort(a,a+lenn);
    for(int i = lenn - 1;i >= 0;i--){
        if(a[i] == a1){
            cout<<y<<" "<<x;
            break;
        }
        if(d == 0){
            x++;
        }else{
            x--;
        }
        if(x == n + 1 && d == 0){
            d = 1;
            x = n;
            y += 1;
        }else if(x == 0 && d == 1){
            d = 0;
            x = 1;
            y += 1;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
