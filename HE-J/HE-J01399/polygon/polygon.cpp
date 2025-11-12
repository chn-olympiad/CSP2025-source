#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,sum = 0,ma = 0;
    cin>>n;
    int a[10000] = { };
    for(int i=1;i <= n;i ++){
        cin>>a[i];
    }
    for(int i=1;i <= n;i ++){
        if(a[i] > ma){
            ma = a[i];
        }
    }
    for(int i=1;i <= n;i ++){
        if(a[i] + a[i+1] + a[i+1+1] > 2 * a[i+1+1] and i >= 1 and i <= 4) {
            sum++;
        }
        if(a[i] + a[i+1] + a[i+1+1] + a[i+1+1+1] > 2 * a[i+1+1+1]){
            sum++;
        }
        if(a[i] + a[i+1] + a[i+1+1] + a[i+1+1+1] + a[i+1+1+1+1] > 2 * a[i+1+1+1+1] and i <= 1 and i >= 1){
            sum++;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
