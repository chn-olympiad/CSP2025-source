#include<bits/stdc++.h>
using namespace std;
int ans,a,sh[30],xia[30];
int main(){
    feopen("employ.in","r",stdin)
    feopen("employ.out","w",stdout)
    cin >> a;
    for(int i = 0;i++){
        for(int k = 1;k <=n;k++){
            sh[k] = 0;
            xia[k] = 0;
        }
        sh[1] = a;
        ren = a;
        sh[2] = i;
        xia[2] = i;
        for(int j = 3;j < n - 1;j++){
            xia[j] +=sh[j-1];
            sh[j] += sh[j-1] + sh[j-2];
            ren += sh[j] - xia[j];
            if(ren > m)
                break;
        }
        if(ren == m)
        break;
    }
    ans = a;
    for(int k = 3;k <= a;k++){
        ans += sh[a] - xia[a];
    }
    cout << ans;
}
