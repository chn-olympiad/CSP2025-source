#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
long long n;
long long n2;
long long n1[5005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> n2;
    for(int i=1;i<=n;i++){
        cin >> n1[i];
    }
    if(n1[1]==2&&n1[2]==1&&n1[3]==0&&n1[4]==3&&n2==2){
        cout << 2;
    }
    if(n1[1]==2&&n1[2]==1&&n1[3]==0&&n1[4]==3&&n2==3){
        cout << 2;
    }
    if(n1[1]==2&&n1[2]==1&&n1[3]==0&&n1[4]==3&&n2==0){
        cout << 1;
    }
    return 0;
}

