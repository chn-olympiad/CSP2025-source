#include<bits/stdc++.h>
using namespace std;

int n,a[50003],ans=0,m=0,d=0,zh=0;

bool b[50003];
void f(int c){
    if(c>m && zh>d*2){
        ans++;
        d=0;
        zh=0;
        return;
    }
    for (int i = 1; i <= m; i++){
        if(b[i]=true){
            zh+=a[i];
            d=max(d,a[i]);
            c++;
            b[i]=false;
            f(c);
            b[i]=true;
        }
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    m=n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    while (m>=3){
        f(1);
        m--;
    }
    cout << ans;
    cout << endl;
    return 0;
}