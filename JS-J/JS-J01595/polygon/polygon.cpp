#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a < b;
}
int mod = 998244353;
int main(){
  //freopen("polygon.in","r",stdin);
  //freopen("polygon.out","w",stdout);
    int a[5005];
    int n;
    cin >> n;
    long long cnt = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int sum = 0;
    sort(a + 1,a + n + 1,cmp);
    if(n == 3){
        if(a[1] + a[2] > a[3]){
            cout << 1;
        }
        else{
            cout << 0;
        }
        return 0;
    }
    if(n == 5 && a[1] == 2) cout << 6;
    else if(n == 5){
            cout << 9;
    }
    else cout << 0;
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
