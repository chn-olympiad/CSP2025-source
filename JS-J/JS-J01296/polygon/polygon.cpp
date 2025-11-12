#include<bits/stdc++.h>
using namespace std;
int n;
int a[50005];
long long ans,sum;
int main(){
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    for(int i = 3;i <= n;i ++){
        ans = 1;
        for(int j = n;j >= n-i+1;j --){
            ans *= j;
        }
        for(int j = i;j >= 1;j --){
            ans /= j;
        }
        sum += ans;
    }
    cout << sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
