#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("polygon1.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int n;
    int a[100001];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i+1]+=a[i];
        cout << a[i];
    }
    return 0;
}
