#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b;
    int a[110],c[110]={0};
    cin >> n >> m;
    b = n*m;
    for(int i=1;i<=b;i++) cin >> a[i];
    int s=a[1];
    for(int i=1;i<=b;i++) c[a[i]]++;
    int x=1,y=1;
    for(int i=100;i>=1;i--){
        if(i == s) break;
        if(c[i]!=0){
            if(y%2 != 0){
                x++;
                if(x>n){
                    y++;
                    x-=1;
                }
            }
            else{
                x--;
                if(x<1){
                    y++;
                    x+=1;
                }
            }
        }
    }
    cout << y << " " << x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
