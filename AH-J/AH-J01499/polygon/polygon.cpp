#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int a[5050];
    int e = 0;
    int munber = 0;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            e = 0;
            for(int z = j;z < n;z++){
                int mmax = max(a[i],a[z]);
                e += a[z];
                if(z - j + 1 >= 3 && 2*mmax < e){
                    munber++;
                }
            }
        }
    }
    cout << munber;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

