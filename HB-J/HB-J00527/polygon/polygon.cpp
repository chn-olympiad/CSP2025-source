#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    int a[50009] = {},a1[50009] = {};
    long long ans = 0,h = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a+1+n);
    if(n < 3){
        return 0;
    }
    if(n == 3){
        if(a[3] * 2 > a[1] + a[2] + a[3]){
            cout << 0;
        }
        else{
            cout << 1;
        }
    }
    else if(n == 4){
        for(int i = 1;i < n;i++){
            a[i] = 0;
            for(int x = 1;x < n;x++){
                h += a[x];
            }
            if(h > a[4]){
                ans++;
            }
        }
        if(a[1] + a[2] > a[3]){
            ans++;
        }
    }
    else if(n == 5){
        for(int q = 0;q < n;q++){
            for(int i = q;i <= n;i++){
				int t = a[q],t1 = a[i];
				for(int x = 1;x <= n;x++){
					a1[x] = 0;
				}
				a[q]= 0;
				a[i]= 0;
				for(int x = 1;x <= n;x++){
					a1[x] = a[x];
				}
				sort(a1+1,a1+1+n);
                h = 0;
                a[i] = 0;
                a[q] = 0;
                for(int x = 1;x < n;x++){
                    h += a1[x];
                }
                if(h > a1[n] && q != i){
                    ans++;
                }
                a[q] = t;
                a[i] = t1;
            }
        }
    }
    cout << ans + 1;
    return 0;
}
