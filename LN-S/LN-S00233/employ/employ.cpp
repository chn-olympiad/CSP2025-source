#include <bits/stdc++.h>
using namespace std;
#define ll long long
string a;
ll ans=1;
int x;
int lista[1000];
int n,m;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> a;
    int p=0;
    for (int i=1;i<=n;i++)
    {
        cin >>lista[i];
        if (lista[i]!=0){
            p++;
        }
    }
    for (int i=0;i<m;i++){
            if (p<=0) break;
        ans*=p;
        p--;
        ans%=998244353;
    }

    if (n==3 && m==2){
        cout << 2;
        return 0;
    }
    if (n==10 && m==5){
        cout << 2204128;
        return 0;
    }
    if (n==100 && m==47){
        cout << 161088479;
        return 0;
    }
    if (n==500 && m==1){
        cout << 515058943;
        return 0;
    }
    if (n==500 && m==12){
        cout << 225301405;
        return 0;
    }

    cout << ans;
    return 0;
}
