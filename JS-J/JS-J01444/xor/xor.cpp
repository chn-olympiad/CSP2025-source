#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll cnt;
ll a[500005];
ll cnt_1;
ll cnt_0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    cnt_1=cnt_0=0;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        if(a[i] == 1) cnt_1++;
        if(a[i] == 0) cnt_0++;
    }
    cnt = 0;
    if(k == 1){
        cnt = cnt_1;
    }
    if(k == 0){
        for(int i =1;i <= n;i++){
            if(a[i] == 0) cnt++;
            else if(a[i+1] == 1){
                cnt++;i++;
            }
        }
    }
    cout<<cnt;
    return 0;
}

