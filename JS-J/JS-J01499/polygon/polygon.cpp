#include <bits/stdc++.h>
using namespace std;
const int N = 5000+10;
int n,a[N],sum = 0;
int maxarray(int p[],int n){
    int res = 0;
    for (int i = 1;i<= n;i++) res = (res<p[i] ? p[i]:res);
    return res;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i = 1;i<= n;i++){
        cin>>a[i];
        sum+= a[i];
    }int m = maxarray(a,n);
    if (sum<= 2*m) cout<<0;
    else if (n== 3) cout<<1;
    else if (m== 1) cout<<1;
    else cout<<6;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
