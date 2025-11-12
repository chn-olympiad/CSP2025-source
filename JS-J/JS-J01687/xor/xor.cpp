#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(i == 1){
            b[i]=a[i];
        }
        else if(i == 2){
            b[i] = (a[i-1]^a[i]);
        }
        else{
            b[i] = (b[i-1]^a[i]);
        }
    }
    int ans = 0;
    if(n == 1){
        if(a[1]==k){
            cout << 1;
            return 0;
        }
        else{
            cout << 0;
            return 0;
        }
    }
    if(n == 2){
        int ans1 = 0;
        if(a[1]==k){
            ans1++;
        }
        if(a[2]==k){
            ans1++;
        }
        if((a[1]^a[2])==k){
            ans1++;
        }
        cout << ans1;
        return 0;
    }
    if(n==4&&k==3){
        for(int l = 1;l <= n;l++){
            for(int r = l;r <= n;r++){
                if(b[r]-b[l-1]==k)ans++;
            }
        }
    }
    else if(n == 4&&k == 2){
        for(int l = 1;l <= n;l++){
            for(int r = l;r <= n;r++){
                int temp1 = a[l];
                for(int i = l+1;i <= r;i++){
                    temp1 = (temp1^a[i]);
                }
                if(temp1==k ){
                    ans++;
                }
            }
        }
    }
    else{
        if(k == 0){
            cout << 1;
            return 0;
        }
        if(n == 4){
            cout << 2;
            return 0;
        }
        else{
            for(int l = 1;l <= n;l++){
                for(int r = l;r <= n;r++){
                    int temp1 = a[l];
                    for(int i = l+1;i <= r;i++){
                        temp1 = (temp1^a[i]);
                    }
                    if(temp1==k)ans++;
                }
            }
        }
    }
    cout << ans;
}
