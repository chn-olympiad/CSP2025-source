#include <iostream>
#include <cstdio>
using namespace std;
int n,k,a[100000],b[100000],sum = 0,least = 0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        b[i] = (a[i] | a[i - 1]);
    }
    for(int i = 2;i <= n;i++){
        for(int j = i - 1;j > least;j--){
            if((b[i]|b[j]) == k){
                sum++;
                least = i;
            }
        }
    }
    cout << sum;
    return 0;
}
