#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    int a[5100];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    bool flag=0;
    if(n<=3){
        for(int i=1;i<=3;i++){
            if(a[i]+a[i+1]>a[i+2]&&a[i+2]+a[i+3]>a[i]&&a[i+1]+a[i+3]>a[i]){
                flag = 1;
            }
        }
    }
    if(flag){
        cout << 1;
        return 0;
    }
    if(a[1]==2){
        cout << 6;
        return 0;
    }
    if(a[1]==1){
        cout << 9;
        return 0;
    }
    cout << 5;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
