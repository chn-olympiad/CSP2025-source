#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,h = 0,ans = 0;
    cin >> m >> n;
    int g[1009] = {};
    for(int i = 1;i <= m * n;i++){
		cin >> g[i];
	}
    ans = g[1];
    sort(g+1,g+1+m*n,cmp);
    bool fl = 1;
    for(int i = 1;i <= m;i++){
        if(!fl){
            break;
        }
        for(int x = 1;x <= n;x++){
            h++;
            if(g[h] == ans){
                fl = 0;
                if(i % 2 == 0){
                    cout << i << ' ' << n - x + 1;
                }
                else{
                    cout << i << ' ' << x;
                }
                break;
            }
        }
    }
    return 0;
}
