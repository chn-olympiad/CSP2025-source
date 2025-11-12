#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 +10;
int a[N]={0};

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n, k;
    cin >> n >>k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int sum = 0;
    for(int i = 1; i < n;){
        if(a[i]^a[i+1] == k){
            sum++;
        }
        i+=2;
    }
    cout << sum;
    return 0;
}