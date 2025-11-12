#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool cmp(ll x,ll y){
    return x > y;
}

int main(){

    ll k;
    cin>>k;
    for(ll i = 1;i <= k;i++){
        ll n,a[100005] = {},b[100005] = {},c[100005] = {},maxn[100005] = {},maxx[100005] = {};
        cin>>n;
        ll sum1 = 0,sum2 = 0,sum3 = 0;
        for(ll x = 1;x <= n;x++){
            cin>>a[x]>>b[x]>>c[x];
            maxn[i] = max(a[x],max(b[x],c[x]));
            if(maxn[i] == a[x]){
                sum1++;
            }
            else if(maxn[i] == b[x]){
                sum2++;
            }
            else{
                sum3++;
            }
        }
        if(max(sum1,max(sum2,sum3)) <= (n / 2)){
            ll sum = 0;
            for(ll x = 1;x <= n;x++){
                sum += max(a[x],max(b[x],c[x]));
            }
            cout<<sum;
        }
        else{
            ll sum = 0,w = max(sum1,max(sum2,sum3));
            if(w == 1){
                ll x[100005] = {};
                bool flag[100005] = {};
                for(ll j = 1;j <= n;j++){
                    x[j] = a[j];
                }
                sort(a + 1,a + n + 1,cmp);
                for(ll j = 1;j <= n / 2;j++){
                    for(ll q = 1;q <= n;q++){
                        if(x[q] == a[j]){
                            flag[q] = true;
                            break;
                        }
                    }
                    sum += a[j];
                }
                for(ll j = 1;j <= n;j++){
                    if(flag[j] != true){
                        sum += max(b[j],c[j]);
                    }
                }
            }
            if(w == 2){
                ll x[100005] = {};
                bool flag[100005] = {};
                for(ll j = 1;j <= n;j++){
                    x[j] = b[j];
                }
                sort(b + 1,b + n + 1,cmp);
                for(ll j = 1;j <= n / 2;j++){
                    for(ll q = 1;q <= n;q++){
                        if(x[q] == b[j]){
                            flag[q] = true;
                            break;
                        }
                    }
                    sum += a[j];
                }
                for(ll j = 1;j <= n;j++){
                    if(flag[j] != true){
                        sum += max(a[j],c[j]);
                    }
                }
            }
            else{
                ll x[100005] = {};
                bool flag[100005] = {};
                for(ll j = 1;j <= n;j++){
                    x[j] = c[j];
                }
                sort(c + 1,c + n + 1,cmp);
                for(ll j = 1;j <= n / 2;j++){
                    for(ll q = 1;q <= n;q++){
                        if(x[q] == c[j]){
                            flag[q] = true;
                            break;
                        }
                    }
                    sum += a[j];
                }
                for(ll j = 1;j <= n;j++){
                    if(flag[j] != true){
                        sum += max(a[j],b[j]);
                    }
                }
            }
            cout<<sum - 1;
        }
    }

    return 0;
}