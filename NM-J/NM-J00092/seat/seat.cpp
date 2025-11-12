#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 +10;
int b[100000]={0};

bool cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m, n, c, r;
    cin >> n >> m;
    for(int i = 1; i <= m*n; i++){
        cin >> b[i];
    }
    int sum = m * n, j = b[1];
    sort(b,b+sum,cmp);
    for(int i = 1; i <= sum; i++){
        if(b[i] == j){
            i+=1;
            if(i%m == 0){
                c =i/m;
            }
            else{
                c = i/m+1;
            }
            if(c%2 == 1){
                r =i-(c-1)*n;
            }
            else{
                r = n - (i-(c-1)*n) + 1;
            }
            cout << c <<" " << r;
            break;  
        }
    }
    return 0;
}