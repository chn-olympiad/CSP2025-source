#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=2147483647;
const ll LLINF=9223372036854775807;
const int N=5e5+10;
int n,k;
int a[N];
int flagA=1;
int flagB=1;
void A(){
    cout << n/2<<endl;
    return;
}
void B(){
    if(k==0){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                cnt++;
            }
            else if(i+1<=n){
                if(a[i]==a[i+1] && a[i]==1){
                    i++;
                    cnt++;
                }
            }
        }
        cout << cnt<<endl;

    }
    if(k==1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                cnt++;
            }
        }
        cout << cnt<<endl;
    }
    return;
}
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin >> n>>k;
   if(k!=0){
        flagA=0;
   }
   if(k!=1 && k!=0){
        flagB=0;
   }
   for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]!=1){
            flagA=0;
        }
        if(a[i]!=1 && a[i]!=0){
            flagB=0;
        }
   }
   if(flagA){
        A();
        return 0;
   }
   else if(flagB){
        B();
        return 0;
   }
    cout << 0;
}
