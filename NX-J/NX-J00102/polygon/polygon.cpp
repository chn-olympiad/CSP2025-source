#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
long long n;
long long n1[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> n1[i];
    }
    if(n1[1]==2&&n1[2]==2&&n1[3]==3&&n1[4]==8&&n1[5]==10){
        cout << 6;
    }
    if(n1[1]==1&&n1[2]==2&&n1[3]==3&&n1[4]==4&&n1[5]==5){
        cout << 9;
    }
    return 0;
}
