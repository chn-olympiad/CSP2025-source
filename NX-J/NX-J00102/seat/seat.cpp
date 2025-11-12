#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
long long a[15][15];
long long b[115];
long long n,m;
long long little_r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> b[i];
    }
    little_r = b[1];
    sort(b+1,b+n*m+1);
    long long jishu=n;
    long long jishu2=1;
    for(int j=m;j>=1;j--){
        if(jishu%2!=0){
            for(int i=n;i>=1;i--){
                a[i][j]=b[jishu2];
                jishu2++;
            }
            jishu--;
            continue;
        }
        if(jishu%2==0){
            for(int i=1;i<=n;i++){
                a[i][j]=b[jishu2];
                jishu2++;
            }
            jishu--;
            continue;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==little_r){
                cout << j << " "<< i;
                break;
            }
        }
    }
    return 0;
}
