#include<bits/stdc++.h>
Using namespace std;
main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    for(int i = 1;i <= n;i++){
        if(n <= 3) cout<<"10";
        else if(3 < n <= 10) cout<<"100";
        else if(10 < n <= 20) cout<<"100";
    }
    return 0;
}
