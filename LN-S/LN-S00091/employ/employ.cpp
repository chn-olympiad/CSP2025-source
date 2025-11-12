#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[1000];
int c[1000];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    int k=n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> c[i];
        if(c[i]==0){
            k--;
        }
    }
    int p=1;
    for(int i=1;i<=k;i++){
        p=p*i%998244353;
    }
    cout << p;
    return 0;
}
