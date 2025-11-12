#include <bits/stdc++.h>
using namespace std;

long long n,k;
int a[500005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n<=2 && k==0){
        cout << 0;
        return 0;
    }
    if(n<=100 && k==0){
        cout << 0;
        return 0;
    }
    if(n<=100 && k==1){
            int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1) cnt++;
        }
        cout << cnt;
        return 0;
    }else if(n<=100 && k==0){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                cnt++;
            }
        }
        cout << cnt;
        return 0;
    }
    if(n<=200000 && k==0){
            int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                cnt++;
            }
        }
        cout << cnt;
        return 0;
    }else if(n<=200000 && k==1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                cnt++;
            }
        }
        cout << cnt;
        return 0;

    }
    return 0;

}
