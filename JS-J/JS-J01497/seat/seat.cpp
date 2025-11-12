#include<bits/stdc++.h>
using namespace std;
int a[100001],id = 0;
int main(){
    freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
    int n,m;cin >> n >> m;
    for(int i = 1;i <= n*m;i++) cin >> a[i];
    int r = a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int j = 1;j <= m;j++){
        if(j%2)
            for(int i = 1;i <= n;i++){id++;if(a[id]==r) cout << j << ' ' << i;}
        else
            for(int i = n;i >= 1;i--){id++;if(a[id]==r) cout << j << ' ' << i;}
    }
    return 0;
}
