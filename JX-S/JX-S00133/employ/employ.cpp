#include<bits/stdc++.h>
using namespace std;
string s;unsigned long long cnt=1;
int a[1000000];
bool b=true;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    cin >> s;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]==0){
            n--;
        }
    }
    if(m==0){
        cout << '0';
        return 0;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            b=false;
            break;
        }
    }
    if(b){
        if(n>=m){
            for(int i=n;i>=1;i--){
                cnt*=i;
            }
            cnt = cnt%998244353;
            cout << cnt;
        }else{
            cout <<'0';
        }

    }else{
        cout << '0';
    }
    return 0;
}
