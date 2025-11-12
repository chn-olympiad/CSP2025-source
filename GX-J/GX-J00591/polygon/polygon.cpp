#include<bits/stdc++.h>
using namespace std;
int num,a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> num;
    for(int i=0;i<num;i++){
        cin >> a[i];
    }
    if(a[0]+a[1]+a[2] < (max(a[0],max(a[1],a[2]))*2)){
        cout << 0;
        return 0;
    }
    cout << 1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
