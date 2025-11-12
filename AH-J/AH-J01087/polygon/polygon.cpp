#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005];

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    int cnt = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                    int ma = max(i,max(j,k)) * 2;
                if(i+j+k > ma){
                    cnt++;
                }
            }
        }
    }
    cout << cnt << endl;
    //solve(n,a);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

